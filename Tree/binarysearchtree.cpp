/******************************************************************************
 
 Online C++ Compiler.
 Code, Compile, Run and Debug C++ program online.
 Write your code in this editor and press "Run" button to compile and execute it.
 
 *******************************************************************************/

#include <iostream>
#include <vector>

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
        
        if(pGreatest->leftChild == greatest) {
            pGreatest->leftChild = NULL;
        } else {
            pGreatest->rightChild = NULL;
        }
        
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

void printPreorder(Node* root) {
    cout<<root->data<<" ";
    
    if(root->leftChild != NULL) {
        printPreorder(root->leftChild);
    }
    
    if(root->rightChild != NULL) {
        printPreorder(root->rightChild);
    }
}

void printPostorder(Node* root) {
    if(root->leftChild != NULL) {
        printPreorder(root->leftChild);
    }
    
    if(root->rightChild != NULL) {
        printPreorder(root->rightChild);
    }
    
    cout<<root->data<<" ";
}

void printBFS(Node* root) {
    vector<Node*> queue;
    
    queue.push_back(root);
    
    while(queue.size() != 0) {
        Node* p = queue[0];
        queue.erase(queue.begin());
        
        cout<<p->data<<" ";
        
        if(p->leftChild != NULL) {
            queue.push_back(p->leftChild);
        }
        
        if(p->rightChild != NULL) {
            queue.push_back(p->rightChild);
        }
    }
}

int getHeight(Node* root) {
    int currentheight = 0;
    
    if(root == NULL) {
        return 0;
    }
    
    int leftHeight = getHeight(root->leftChild);
    int rightHeight = getHeight(root->rightChild);
    
    if(leftHeight < rightHeight) {
        currentheight = rightHeight + 1;
    } else {
        currentheight = leftHeight + 1;
    }
    
    return currentheight;
}

void printSpiral(Node* root) {
    vector<Node*> stack1;
    vector<Node*> stack2;
    
    stack1.push_back(root);
    
    while(stack1.size() > 0 || stack2.size() > 0) {
        
        while(stack1.size() > 0) {
            int size = stack1.size()-1;
            Node* node = stack1[size];
            stack1.erase(stack1.begin() + size);
            cout<<node->data<<" ";
            if(node->leftChild != NULL) {
                stack2.push_back(node->leftChild);
            }
            if(node->rightChild != NULL) {
                stack2.push_back(node->rightChild);
            }
            node = NULL;
        }
        
        while(stack2.size() > 0) {
            int size = stack2.size()-1;
            Node* node = stack2[size];
            stack2.erase(stack2.begin() + size);
            cout<<node->data<<" ";
            if(node->rightChild != NULL) {
                stack1.push_back(node->rightChild);
            }
            if(node->leftChild != NULL) {
                stack1.push_back(node->leftChild);
            }
            node = NULL;
        }
        
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
    
    //printInorder(root);
    
    //deleteNode(root, 20);
    
    //printBFS(root);
    
    cout<<getHeight(root)<<"\n";
    
    printSpiral(root);
    
    return 0;
}
