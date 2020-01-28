/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

vector<int> rearrange(vector<int> &A) {
    int low, mid, high, temp;
    low = mid = 0;
    high = A.size()-1;
    
    while(mid <= high) {
        switch(A[mid]) {
            case 0:
                temp = A[low];
                A[low] = A[mid];
                A[mid] = temp;
                low++;
                mid++;
                break;
                
            case 1:
                mid++;
                break;
                
            case 2:
                temp = A[high];
                A[high] = A[mid];
                A[mid] = temp;
                high--;
                break;
        }
    }
    
    return A;
}

int main()
{
    vector<int> a;
    
    a.push_back(0);
    a.push_back(1);
    a.push_back(2);
    a.push_back(2);
    a.push_back(0);
    a.push_back(1);
    a.push_back(2);
    a.push_back(0);
    a.push_back(0);
    a.push_back(1);
    a.push_back(1);
    
    a = rearrange(a);
    
    for(int i=0; i<=a.size()-1; i++) {
        cout<<a[i]<<" ";
    }

    return 0;
}

