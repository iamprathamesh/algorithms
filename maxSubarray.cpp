#include <iostream>
#include <vector>

using namespace std;

vector<int> maxSubarray(vector<int> &A) {
    int maxSum = A[0];
    int maxSoFar = 0;
    int start=0, end=0, temp=0;
    vector<int> a;
    
    for(int i=0; i<=A.size()-1; i++) {
        maxSoFar = maxSoFar + A[i];
        
        if(maxSum < maxSoFar) {
            maxSum = maxSoFar;
            start = temp;
            end = i;
        }
        
        if(maxSoFar < 0) {
            maxSoFar = 0;
            temp = i+1;
        }
    }
    
    for(int i=start; i<=end; i++) {
        a.push_back(A[i]);
    }
    
    //return maxSum;
    return a;
}

int main()
{
    vector<int> a;
    
    a.push_back(-1);
    a.push_back(3);
    a.push_back(2);
    a.push_back(-4);
    a.push_back(6);
    a.push_back(-7);
    
    vector<int> A = maxSubarray(a);
    
    for(int i=0; i<=A.size()-1; i++) {
        cout<<A[i]<<" ";
    }
    
    //cout<<maxSubarray(a);
    
    return 0;
}
