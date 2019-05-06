#ifndef BTREE_H
#define BTREE_H
#include "student.h"

class BTree{
    public:
        BTree();        //constructor
        ~BTree();       //destructor
        bool isEmpty(); //if the list is empty return true 
        student* lookup(int k); //look up a student with student number
        void traversal();       //inorder traversal tree
        void insert(int k, student & obj);  //insert a new student with student number
    private:
        static const int maxCap = 3;
        struct Node{
            int key[maxCap];
            student* data[maxCap];
            Node* child[maxCap+1];
            int size;
        };
        Node* root;
        void destroyTree(Node* root);
        Node* search(Node* root, int k);
        void traversal(Node* &root);          
        bool insert(Node* &root, int &k, student* &dptr, Node* &newNode);   
};

#endif
