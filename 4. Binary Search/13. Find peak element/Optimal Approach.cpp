#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int id;
    int contactno;
    char name[20];
    char address[50];

    TreeNode *left;
    TreeNode *right;
};

class td : public TreeNode // class for functions or operation
{
private:
    TreeNode* root;
    int totalperson;

public:
    td();
    bool respond();
    int showmenu();
    bool insertobject();
    bool addtoarray(int, char*, char*, int);
    bool listdirectory();
    bool searchTreeNode();
    bool updateTreeNode();
    bool deleteTreeNode();

    bool insertnode(TreeNode *newNode);
    bool insertdata(int, char*, char*, int);
    bool inputnode();

    void PrintOne(TreeNode *T);
    bool PrintTree();
    void PrintAll(TreeNode *T);
    bool Searchnode(int id);
    bool Search();

    bool Deletenode(int id);
    bool Deletee();

    bool Updatenode(int id);
    bool Update();
};

td::td() // default constructor
{
    root = NULL;
    totalperson = 0;
}

bool td::insertnode(TreeNode *newNode)
{
    TreeNode *temp;
    TreeNode *back;

    temp = root;
    back = NULL;

    while (temp != NULL) // Loop till temp falls out of the tree
    {
        back = temp;
        if (newNode->id < temp->id)
            temp = temp->left;
        else
            temp = temp->right;
    }

    // Now attach the new node to the node that back points to
    if (back == NULL) // Attach as root node in a new tree
        root = newNode;
    else
    {
        if (newNode->id < back->id)
            back->left = newNode;
        else
            back->right = newNode;
    }
    return(true);
}

bool td::insertdata(int id, char *name, char *address, int contactno)
{
    TreeNode *newNode;

    // Create the new node and copy data into it
    newNode = new TreeNode();
    newNode->id = id;
    strcpy(newNode->name, name);
    strcpy(newNode->address, address);
    newNode->contactno = contactno;
    newNode->left = newNode->right = NULL;

    // Call other Insert() to do the actual insertion
    return (insertnode(newNode));
}

bool td::inputnode()
{
    cout << "*" << endl;
    cout << "  Telephone Directory: Insert Menu" << endl;
    cout << "*" << endl;

    int id;
    char name[20];
    char address[50];
    int contactno;
    int optionofsave;

    // Takes the value of the record
    cout << "Enter Id: ";
    cin >> id;
    cin.ignore(); // Ignore the newline character left in the buffer

    cout << "Enter Name: ";
    cin.getline(name, 20);

    cout << "Enter Contact No: ";
    cin >> contactno;
    cin.ignore(); // Ignore the newline character left in the buffer

    cout << "Enter Address: ";
    cin.getline(address, 50);

    cout << "Press 1 to save, 0 to not save: ";
    cin >> optionofsave;

    if (optionofsave == 1) // if want to save then send values to the addtoarray function
    {
        insertdata(id, name, address, contactno);
        cout << "Record saved successfully." << endl;
    }
    else if (optionofsave == 0)
    {
        return true;
    }

    char insertagain;
    cout << "Want to insert another record? [y/n]: ";
    cin >> insertagain;

    if (insertagain == 'y')
    {
        return false;
    }
    else if (insertagain == 'n')
    {
        return true;
    }
    return true;
}

bool td::respond() // function to get the response of the user for particular functions
{
    int option;
    option = showmenu();
    bool result = true;

    switch (option)
    {
    case 1:
        do {
            system("CLS"); // clear screen
            result = inputnode(); // calls the insert function
        } while (result == false); // if false comes, the do while starts again and if true loop ends
        break;
    case 2:
        do {
            system("CLS");
            result = PrintTree();
        } while (result == false);
        break;
    case 3:
        do {
            system("CLS");
            result = Search();
        } while (result == false);
        break;
    case 4:
        do {
            system("CLS");
            result = Update();
        } while (result == false);
        break;
    case 5:
        do {
            system("CLS");
            result = Deletee();
        } while (result == false);
        break;
    case 6:
        return false;
    }
    return true;
}

int td::showmenu() // shows menu of the program
{
    system("CLS");
    int option;

    cout << "*" << endl;
    cout << "   Telephone Directory: Main Menu" << endl;
    cout << "*" << endl;

    cout << "\n\n1. Insert a new record\n2. List Records\n3. Search a Record\n";
    cout << "4. Update a record(using name or ID)\n5. Delete a Record\n6. Exit program";

    cout << "\n\nSelect Option [1, 2, 3, 4, 5, 6]: ";
    cin >> option;

    return option;
}

void td::PrintOne(TreeNode *T)
{
    cout << T->id << "\t\t" << T->name << "\t\t" << T->address << "\t\t" << T->contactno << "\t\t\n";
}

void td::PrintAll(TreeNode *T)
{
    if (T != NULL)
    {
        PrintAll(T->left);
        PrintOne(T);
        PrintAll(T->right);
    }
}

bool td::PrintTree()
{
    PrintAll(root);

    cout << "\nPress 'm' to go to Main menu:" << endl;
    char m;
    cin >> m;
    if (m == 'm')
    {
        return true;
    }
    return true;
}

bool td::Searchnode(int id)
{
    TreeNode *curr = root;
    while (curr != NULL)
    {
        if (curr->id == id)
            break;

        if (curr->id < id)
            curr = curr->right;
        else
            curr = curr->left;
    }
    if (curr == NULL)
    {
        cout << "\nID does not found:\n";
        return true;
    }
    cout << "\nFound the record:\n";
    PrintOne(curr);

    return true;
}

bool td::Search()
{
    cout << "*" << endl;
    cout << "  Telephone Directory: Search Menu" << endl;
    cout << "*" << endl;

    int idtofind;
    cout << "\nEnter id to be found: ";  // takes id to be searched
    cin >> idtofind;
    if (Searchnode(idtofind))
    {
    }
    else
    {
    }

    char searchagain;
    cout << "\nDo you want to search another record? [y/n]";    // search again
    cin >> searchagain;
    if (searchagain == 'y')
        return false;
    else if (searchagain == 'n')
        return true;

    return true;
}

bool td::Deletenode(int id)
{
    TreeNode *curr = root;
    TreeNode *parent = NULL;

    while (curr != NULL)
    {
        if (curr->id == id)
            break;

        parent = curr;
        if (curr->id < id)
            curr = curr->right;
        else
            curr = curr->left;
    }

    if (curr == NULL)
    {
        cout << "\nID does not found:\n";
        return true;
    }

    if (curr->left == NULL && curr->right == NULL)
    {
        if (parent == NULL)
        {
            root = NULL;
        }
        else if (parent->left == curr)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }
        delete curr;
    }
    else if (curr->left == NULL)
    {
        if (parent == NULL)
        {
            root = curr->right;
        }
        else if (parent->left == curr)
        {
            parent->left = curr->right;
        }
        else
        {
            parent->right = curr->right;
        }
        delete curr;
    }
    else if (curr->right == NULL)
    {
        if (parent == NULL)
        {
            root = curr->left;
        }
        else if (parent->left == curr)
        {
            parent->left = curr->left;
        }
        else
        {
            parent->right = curr->left;
        }
        delete curr;
    }
    else
    {
        TreeNode *succ = curr->right;
        TreeNode *succParent = curr;

        while (succ->left != NULL)
        {
            succParent = succ;
            succ = succ->left;
        }

        curr->id = succ->id;
        strcpy(curr->name, succ->name);
        strcpy(curr->address, succ->address);
        curr->contactno = succ->contactno;

        if (succParent->left == succ)
        {
            succParent->left = succ->right;
        }
        else
        {
            succParent->right = succ->right;
        }

        delete succ;
    }

    cout << "Record deleted successfully." << endl;
    return true;
}

bool td::Deletee()
{
    cout << "*" << endl;
    cout << "  Telephone Directory: Delete Menu" << endl;
    cout << "*" << endl;

    int id;
    cout << "Enter ID to delete: ";
    cin >> id;

    Deletenode(id);

    char deleteagain;
    cout << "\nDo you want to delete another record? [y/n]: ";
    cin >> deleteagain;
    if (deleteagain == 'y')
        return false;
    else if (deleteagain == 'n')
        return true;

    return true;
}

bool td::Updatenode(int id)
{
    TreeNode *curr = root;
    while (curr != NULL)
    {
        if (curr->id == id)
            break;

        if (curr->id < id)
            curr = curr->right;
        else
            curr = curr->left;
    }
    if (curr == NULL)
    {
        cout << "\nID not found:\n";
        return true;
    }
    cout << "\nFound the record:\n";
    PrintOne(curr);

    cout << "\nEnter new details:\n";

    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(curr->name, 20);

    cout << "Enter Contact No: ";
    cin >> curr->contactno;

    cout << "Enter Address: ";
    cin.ignore();
    cin.getline(curr->address, 50);

    cout << "\nRecord updated successfully." << endl;

    return true;
}

bool td::Update()
{
    cout << "*" << endl;
    cout << "  Telephone Directory: Update Menu" << endl;
    cout << "*" << endl;

    int id;
    cout << "Enter ID to update: ";
    cin >> id;

    Updatenode(id);

    char updateagain;
    cout << "\nDo you want to update another record? [y/n]: ";
    cin >> updateagain;
    if (updateagain == 'y')
        return false;
    else if (updateagain == 'n')
        return true;

    return true;
}

int main() // main function
{
    td t;

    t.respond(); // call the respond function once

    return 0;
}
