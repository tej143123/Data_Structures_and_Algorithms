#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    string data;
    Node *next;
    Node *back;

    Node(string &url, Node  *next1, Node *back1){
        data = url;
        next = next1;
        back = back1;
    }

    Node(string &url){
        data = url;
        next = nullptr;
        back = nullptr;
    }
};

class Browser
{
    public:
    Node *currentPage;
    Browser(string &homepage)
    {
        currentPage = new Node(homepage);
    }

    void visit(string &url)
    {
       Node *nextPage = new Node(url);
       currentPage->next = nextPage;
       nextPage->back = currentPage;
       currentPage = nextPage;
    }

    string back(int steps)
    {
        while(steps > 0){
            if(currentPage->back){
                currentPage = currentPage->back;
                steps--;
            }
            else{
                break;
            }
        }
        return currentPage->data;
    }

    string forward(int steps)
    {
        while(steps > 0){
            if(currentPage->next){
                currentPage = currentPage->next;
                steps--;
            }
            else{
                break;
            }
        }
        return currentPage->data;
    }
};
