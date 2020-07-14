/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class Node {
  public:
    Node* leftChild;
    int data;
    Node* rightChild;
    
    Node(int data) {
        this->data = data;
        leftChild = NULL;
        rightChild = NULL;
    }
};

void insertNode(Node* root, int data) {
    Node* node = root;
    Node* p = root;
    Node* obj = new Node(data);
    
    while(node != NULL) {
        p = node;
        
        if(data < node->data) {
            node = node->leftChild;
        } else {
            node = node->rightChild;
        }
    }
    
    if(data < p->data) {
        p->leftChild = obj;
    } else {
        p->rightChild = obj;
    }
}

void deleteNode(Node* root, int data) {
    Node* node = root;
    Node* p = root;
    
    while(node->data != data) {
        p = node;
        
        if(data < node->data) {
            node = node->leftChild;
        } else {
            node = node->rightChild;
        }
    }
    
    if(node->leftChild == NULL && node->rightChild == NULL) {
        if(p->leftChild == node) {
            p->leftChild = NULL;
        } else {
            p->rightChild = NULL;
        }
    } else if(node->leftChild == NULL && node->rightChild != NULL) {
        if(p->leftChild == node) {
            p->leftChild = node->rightChild;
        } else {
            p->rightChild = node->rightChild;
        }
    } else if(node->leftChild != NULL && node->rightChild == NULL) {
        if(p->leftChild == node) {
            p->leftChild = node->leftChild;
        } else {
            p->rightChild = node->leftChild;
        }
    } else if(node->leftChild != NULL && node->rightChild != NULL) {
        Node* greatest = node;
        Node* pGreatest = node;
        
        greatest = greatest->leftChild;
        
        while(greatest->rightChild != NULL) {
            pGreatest = greatest;
            greatest = greatest->rightChild;
        }
        
        node->data = greatest->data;
        pGreatest->rightChild = NULL;
        
    }
}

void printInorder(Node* root) {
    if(root->leftChild != NULL) {
        printInorder(root->leftChild);
    }
    
    cout<<root->data<<" ";
    
    if(root->rightChild != NULL) {
        printInorder(root->rightChild);
    }
}

int main()
{
    Node* root = new Node(40);
    
    insertNode(root, 60);
    insertNode(root, 20);
    insertNode(root, 10);
    insertNode(root, 30);
    insertNode(root, 50);
    
    printInorder(root);
    
    deleteNode(root, 30);
    
    printInorder(root);

    return 0;
}
