#include "BTree.h"
BTree::BTree()
{
    root = NULL;
}
BTree::~BTree()
{
    destroyTree(root);   
}
bool BTree::isEmpty()
{
    return root == NULL;
}
void BTree::destroyTree(Node* root)
{
    if (root != NULL){
        int i = 0;
        while(i<=root->size && root->key[i]!=0){
            destroyTree(root->child[i]);
            i = i + 1;
        }
        delete root;
    }
}
student* BTree::lookup(int k)
{
    Node* ptr = search(root, k);
    if (ptr==NULL)
        return 0;
    else{
        int i=0;
        while(i < ptr->size && ptr->key[i]<k)
            i++;
        if(ptr->key[i]==k)
            return ptr->data[i];
    }
}
BTree::Node* BTree::search(Node* root, int k)
{
    if(root==NULL)
        return NULL;
    int i=0;
    while(i < root->size && root->key[i]<k)
        i++;
    if(root->key[i]==k)
        return root;
    if(root->child[0] == 0)
        return NULL;
    return search(root->child[i],k);
}
void BTree::traversal()
{
     traversal(root);
}
void BTree::traversal(Node* &root)
{
    int i;
    for(i=0; i<root->size;i++){
        if (root->child[0]!=0){     
           traversal(root->child[i]);
        }
        cout << "_________________________________________"<< endl
             << " Student Number: " << root->key[i]<< endl
             << "   Student Name: " << root->data[i]->getStudentName()<< endl;
    }
    if (root->child[0]!=0)
        traversal(root->child[i]);
}
void BTree::insert(int k, student & obj)
{
    if (root == 0) {
        root = new Node;
        root->key[0]=k;
        root->data[0]= & obj;
        root->child[0]=0;
        root->size = 1;
    } else {
        Node* newNode = new Node;
        student* dptr = & obj;
        bool split = insert(root, k, dptr, newNode);  
        if (split) {
            Node* newRoot = new Node;
            newRoot->size = 1;
            newRoot->child[0] = root;
            newRoot->key[0] = k;
            newRoot->data[0] = dptr;
            newRoot->child[1] = newNode;
            root = newRoot;
        }
    }
}
bool BTree::insert(Node* &root, int &k, student* &dptr, Node* &newNode)
{
    if (root->child[0] == 0) {    // leaf node
        if (root->size < maxCap) {   // leaf node not full
            int i = root->size-1;
            while (i >= 0 && root->key[i]>k){  //inorder insert
                root->key[i+1] = root->key[i];
                root->data[i+1] = root->data[i];
                i--;
            }
            root->key[i+1] = k;
            root->data[i+1] = dptr;
            root->size ++;  
            return false;
        }else {    // leaf node full altogether there are 4 keys, 4 data pointers
            int tempkey[maxCap+1];
            student* tempdata[maxCap+1];

            int i = maxCap;
            int j = maxCap-1;            
            while (j >= 0 && root->key[j]>k){
                tempkey[i] = root->key[j];
                tempdata[i] = root->data[j];
                i--;
                j--;
            }
            tempkey[i] = k;
            tempdata[i] = dptr;
            i--;
            while (j >= 0){
                tempkey[j] = root->key[j];
                tempdata[j] = root->data[j];
                j--;
            }   //temp stored 4 keys & 4 data in order 

            for(int i=0; i<maxCap-1; i++){
                root->key[i] = tempkey[i];
                root->data[i] = tempdata[i];
            }                             //1st and 2nd copy back to root  
            root->size = 2;
            k = tempkey[maxCap-1];      //3rd later on copy to newRoot
            dptr = tempdata[maxCap-1];
                        
            newNode = new Node;
            newNode->key[0] = tempkey[maxCap];  //4th copy to newNode
            newNode->data[0] = tempdata[maxCap];
            newNode->child[0] =0;
            newNode->size = 1;
            return true;
        }
    } else { // internal node
        int p=0;
        while(p < root->size && root->key[p]<k)
            p++;
        bool split = insert(root->child[p], k, dptr, newNode);
        if (split) { // child wants to put a new combo to this node
            if (root->size < maxCap) { // internal node not full            
                int i = root->size-1;
                while (i >= 0 && root->key[i]>k){  //inorder insert
                    root->key[i+1] = root->key[i];
                    root->data[i+1] = root->data[i];
                    root->child[i+2] = root->child[i+1];
                    i--;
                }
                root->key[i+1] = k;
                root->data[i+1] = dptr;
                root->child[i+2] = newNode;
                root->size ++;
                return false;
            } else { // internal node full altogether there are 4 keys, 
                // 4 data pointers and 5 not-null child pointers                                          
                int tempkey[maxCap+1];
                student* tempdata[maxCap+1];
                Node* tempchild[maxCap+2];                

                int i = maxCap;
                int j = maxCap-1;            
                while (j >= 0 && root->key[j]>k){
                    tempkey[i] = root->key[j];
                    tempdata[i] = root->data[j];
                    tempchild[i+1] = root->child[j+1];
                    i--;
                    j--;
                }
                tempkey[i] = k;
                tempdata[i] = dptr;
                tempchild[i+1] = newNode;
                i--;
                while (j >= 0){
                    tempkey[j] = root->key[j];
                    tempdata[j] = root->data[j];
                    tempchild[j+1] = root->child[j+1];
                    j--;
                }   //temp store 4 keys & 4 data & 4 child in order
                //* root child [0] no move, and the new child is newNode

                for(int i=0; i<maxCap-1; i++){  //1st and 2nd copy back to root
                    root->key[i] = tempkey[i];
                    root->data[i] = tempdata[i];
                    root->child[i+1] = tempchild[i+1]; //#1-#2 child copy back to root
                }
                root->size = 2;
                root->child[maxCap] = 0;     //*p3 in root = 0           
                k = tempkey[maxCap-1];       //3rd later on copy to newRoot
                dptr = tempdata[maxCap-1];  
            
                Node* newNewNode = new Node;
                newNewNode->key[0]= tempkey[maxCap];     //4th copy to newNode
                newNewNode->data[0]= tempdata[maxCap];
                newNewNode->child[0]= tempchild[maxCap]; //#3 child copy to newNode p0
                newNewNode->child[1]= tempchild[maxCap+1]; //#4 child copy to newNode p1
                newNewNode->size = 1;
                newNode = newNewNode;
                return true;
            }
        }
    }
    return false;
}
