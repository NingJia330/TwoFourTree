#ifndef BST_H
#define BST_H
#include "student.h"

class BST{
    public:
        BST();        //constructor
        ~BST();       //destructor
        void traversal();   //inorder traversal tree
        void insert(string k, student &obj);  //insert a new student with name
        bool isEmpty(); //if the list is empty return true 
    private:
        struct Node{
            student* data;
            string key;
            Node* left;
            Node* right;
        };
        Node* root;
        void destroyTree(Node* root);
        void traversal(Node* root);
        void insert(Node* &root, string k, student &obj);
};

#endif

