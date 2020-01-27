/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

vector<int> removeDuplicates(vector<int> &A) {
    int ptr = -1;
    vector<int> removedDuplicates;
    
    for(int i=0; i<=A.size()-1; i++) {
        if(A[i] != A[i+1]) {
            ptr++;
            A[ptr] = A[i];
        }
    }
    
    for(int i=0; i<=ptr; i++) {
        removedDuplicates.push_back(A[i]);
    }
    
    return removedDuplicates;
}

int main()
{
    vector<int> A;
    
    A.push_back(1);
    A.push_back(3);
    A.push_back(4);
    A.push_back(4);
    A.push_back(6);
    A.push_back(7);
    A.push_back(7);
    A.push_back(7);
    A.push_back(9);
    A.push_back(9);
    
    A = removeDuplicates(A);
    
    for(int i=0; i<=A.size()-1; i++) {
        cout<<A[i]<<" ";
    }
    
    return 0;
}

