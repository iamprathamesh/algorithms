/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

void getMinJumps(vector<int> &data, vector<int> &minJumps, vector<int> &jumpPath) {
    minJumps[0] = 0;
    jumpPath[0] = 0;
    
    for(int i=1; i<data.size(); i++) {
        for(int j=0; j<i; j++) {
            if(data[j] >= i-j) {
                if(minJumps[i] != -1) {
                    if(minJumps[j] < minJumps[i]) {
                        minJumps[i] = minJumps[j] + 1;
                        jumpPath[i] = j;
                    }
                } else {
                    minJumps[i] = minJumps[j] + 1;
                    jumpPath[i] = j;
                }
            }
        }
    }
}

int main()
{
    vector<int> input;
    
    input.push_back(2);
    input.push_back(7);
    input.push_back(4);
    input.push_back(1);
    input.push_back(5);
    input.push_back(9);
    input.push_back(8);
    input.push_back(6);
    input.push_back(3);
    
    vector<int> minNoOfJumps(input.size(), -1);
    vector<int> jumpPath(input.size(), 0);
    
    getMinJumps(input, minNoOfJumps, jumpPath);
    
    for(int i=0; i<input.size(); i++) {
        cout<<input[i]<<" ";
    }
    
    cout<<"\n";
    
    for(int i=0; i<minNoOfJumps.size(); i++) {
        cout<<minNoOfJumps[i]<<" ";
    }
    
    cout<<"\n";
    
    for(int i=0; i<jumpPath.size(); i++) {
        cout<<jumpPath[i]<<" ";
    }
    
    cout<<"\n"<<"Minimum no. of jumps required: "<<minNoOfJumps[minNoOfJumps.size()-1]<<"\n";
    
    cout<<"Jump path: \n";
    int pathPointer = jumpPath.size()-1;
    vector<int> revArr;
    while(pathPointer > 0) {
        revArr.push_back(pathPointer);
        pathPointer = jumpPath[pathPointer];
    }
    
    for(int i=revArr.size()-1; i>=0; i--) {
        cout<<revArr[i]<<" ";
    }
    
    
    return 0;
}

