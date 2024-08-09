#include <iostream>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>

class Contact {
public:
    std::string name;
    std::string phoneNumber;
    std::string group;

    Contact(std::string n, std::string p, std::string g) : name(n), phoneNumber(p), group(g) {}
};

class TelephoneDirectory {
private:
    std::vector<Contact> contacts;

public:
    void addContact(const std::string& name, const std::string& phoneNumber, const std::string& group) {
        // Check for duplicates
        for (const auto& contact : contacts) {
            if (contact.name == name && contact.phoneNumber == phoneNumber) {
                std::cout << "Contact already exists: " << name << " - " << phoneNumber << std::endl;
                return;
            }
        }
        contacts.emplace_back(name, phoneNumber, group);
        std::cout << "Contact added: " << name << " - " << phoneNumber << " (Group: " << group << ")" << std::endl;
    }

    void searchContact(const std::string& name) {
        std::cout << "Searching for: " << name << std::endl;
        for (const auto& contact : contacts) {
            if (contact.name == name) {
                std::cout << "Found: " << contact.name << " - " << contact.phoneNumber << " (Group: " << contact.group << ")" << std::endl;
                return;
            }
        }
        std::cout << "Contact not found." << std::endl;
    }

    void deleteContact(const std::string& name) {
        auto it = std::remove_if(contacts.begin(), contacts.end(), [&](const Contact& contact) {
            return contact.name == name;
        });
        if (it != contacts.end()) {
            contacts.erase(it, contacts.end());
            std::cout << "Contact deleted: " << name << std::endl;
        } else {
            std::cout << "Contact not found: " << name << std::endl;
        }
    }

    void displayAllContacts() {
        std::cout << "All Contacts:" << std::endl;
        for (const auto& contact : contacts) {
            std::cout << contact.name << " - " << contact.phoneNumber << " (Group: " << contact.group << ")" << std::endl;
        }
    }

    void importContacts(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cout << "Failed to open file: " << filename << std::endl;
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string name, phoneNumber, group;
            std::getline(ss, name, ',');
            std::getline(ss, phoneNumber, ',');
            std::getline(ss, group);
            addContact(name, phoneNumber, group);
        }
        file.close();
        std::cout << "Contacts imported from " << filename << std::endl;
    }

    void exportContacts(const std::string& filename) {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cout << "Failed to open file: " << filename << std::endl;
            return;
        }

        for (const auto& contact : contacts) {
            file << contact.name << "," << contact.phoneNumber << "," << contact.group << "\n";
        }
        file.close();
        std::cout << "Contacts exported to " << filename << std::endl;
    }
};

int main() {
    TelephoneDirectory directory;
    int choice;
    std::string name, phoneNumber, group, filename;

    do {
        std::cout << "\nTelephone Directory Menu:\n";
        std::cout << "1. Add Contact\n";
        std::cout << "2. Search Contact\n";
        std::cout << "3. Delete Contact\n";
        std::cout << "4. Display All Contacts\n";
        std::cout << "5. Import Contacts\n";
        std::cout << "6. Export Contacts\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter phone number: ";
                std::getline(std::cin, phoneNumber);
                std::cout << "Enter group: ";
                std::getline(std::cin, group);
                directory.addContact(name, phoneNumber, group);
                break;
            case 2:
                std::cout << "Enter name to search: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                directory.searchContact(name);
                break;
            case 3:
                std::cout << "Enter name to delete: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                directory.deleteContact(name);
                break;
            case 4:
                directory.displayAllContacts();
                break;
            case 5:
                std::cout << "Enter filename to import: ";
                std::cin >> filename;
                directory.importContacts(filename);
                break;
            case 6:
                std::cout << "Enter filename to export: ";
                std::cin >> filename;
                directory.exportContacts(filename);
                break;
            case 7:
                std::cout << "Exiting the program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 7);

    return 0;
}