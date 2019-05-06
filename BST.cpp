#include "BST.h"
BST::BST()
{
    root = NULL;
}
BST::~BST()
{
    destroyTree(root);   
}
void BST::destroyTree(Node* root)
{
    if(root!=NULL) {
        destroyTree(root->left);
        destroyTree(root->right);
        delete root->data;
        delete root;
    }
}
void BST::traversal()
{
    traversal(root);
}
void BST::traversal(Node* root)
{
    if (root == NULL){
       return;
    }else{
        traversal(root->left);
        cout << "_________________________________________"<< endl
             << "   Student Name: " << root->key<< endl
             << " Student Number: " << root->data->getStudentNumber()<< endl;
        traversal(root->right);
    }
}
void BST::insert(string k, student &obj)
{
    insert(root, k, obj);
}
void BST::insert(Node* &root, string k, student &obj)
{
    if (root == NULL){
        root = new Node;
        root->data = &obj;
        root->key = k;
        root->left = NULL;
        root->right = NULL;
        return;
    }
    else if (root->key > k){  
       insert(root->left, k, obj);
    }else {
       insert(root->right, k, obj);
    }
}
bool BST::isEmpty()
{
    return root == NULL;
}
