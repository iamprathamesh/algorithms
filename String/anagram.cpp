/******************************************************************************

 

                              Online C++ Compiler.

               Code, Compile, Run and Debug C++ program online.

Write your code in this editor and press "Run" button to compile and execute it.

 

*******************************************************************************/

 

#include <iostream>

#include <vector>

#include <string>

#include <unordered_map>

 

using namespace std;

 

int NoOfAnagrams(string longString, string subString) {

    int count = 0;

    int startIndex = 0;

    int endIndex = subString.size()-1;

    bool isAnagram;

   

    

    

    while(endIndex <= longString.size()-1) {

        unordered_map<char, int> subStringMap;

        isAnagram = true;

       

        for(char alphabet : subString) {

            subStringMap[alphabet] = subStringMap[alphabet] + 1;

        }

       

        for(int i=startIndex; i<=endIndex; i++) {

            subStringMap[longString[i]] = subStringMap[longString[i]] - 1;

            if(subStringMap[longString[i]] < 0) {

                isAnagram = false;   

            }

        }

       

        if(isAnagram) {

            count = count + 1;

        }

       

        startIndex++;

        endIndex++;

    }

   

    return count;

   

}

 

int main()

{

    string longString, subString;

   

    cout<<"Enter complete string:\n";

    getline(cin, longString);

    cout<<"Enter string to check for all anagrams:\n";

    getline(cin, subString);

   

    for(char alphabet : longString) {

        alphabet = tolower(alphabet);

    }

   

    for(char alphabet : subString) {

        alphabet = tolower(alphabet);

    }

   

    int count = NoOfAnagrams(longString, subString);

   

    cout<<"The total number of anagrams for given string is:\n";

    cout<<count;

   

    return 0;

}
