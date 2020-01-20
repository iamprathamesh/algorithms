/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

vector<int> convertToPrefixSuffixArray(vector<char> &substring) {
    vector<int> convertedVec;
    convertedVec.push_back(0);
    
    int i = 0;
    int j = i+1;
    int temp;
    
    while(j <= substring.size()-1) {
        if(substring[i] == substring[j]) {
            convertedVec.push_back(i+1);
            temp = i;
            i++;
            j++;
        } else if(i > 0) {
            if(temp >= 0) {
                i = convertedVec[temp];
                temp = -1;
            } else {
                i = convertedVec[i];
            }
        } else {
            convertedVec.push_back(0);
            j++;
        }
    }
    
    return convertedVec;
}

bool matchSubstring(vector<char> &fullStr, vector<char> &subStr, vector<int> &convertedInd) {
    int fullStrPtr = 0;
    int subStrPtr = 0;
    
    while(fullStrPtr <= fullStr.size()-1) {
        if(subStrPtr <= subStr.size()-1) {
            if(fullStr[fullStrPtr] == subStr[subStrPtr]) {
                fullStrPtr++;
                subStrPtr++;
            } else if(subStrPtr > 0) {
                subStrPtr = convertedInd[subStrPtr-1];
            } else {
                fullStrPtr++;
            }
        } else {
            return true;
        }
        
    }
    
    return false;
}

int main()
{
    vector<char> a;
    vector<char> b;
    
    a.push_back('a');
    a.push_back('b');
    a.push_back('d');
    a.push_back('b');
    a.push_back('c');
    a.push_back('a');
    a.push_back('a');
    a.push_back('b');
    a.push_back('a');
    a.push_back('b');
    a.push_back('c');
    a.push_back('a');
    a.push_back('c');
    a.push_back('b');
    a.push_back('a');
    a.push_back('b');
    a.push_back('c');
    a.push_back('a');
    
    b.push_back('a');
    b.push_back('b');
    b.push_back('a');
    b.push_back('b');
    b.push_back('c');
    b.push_back('a');
    
    vector<int> convertedToSufandPref = convertToPrefixSuffixArray(a);
    
    bool ans = matchSubstring(a, b, convertedToSufandPref);
    
    if(ans) {
        cout<<"OK";
    } else {
        cout<<"NOT OK";
    }
    
    return 0;
}

