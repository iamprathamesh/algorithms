/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string inp;
    string out = "";
    int counter = 0;
    char current;
    
    cout<<"Enter a string: \n";
    getline(cin, inp);
    
    current = inp[0];
    for(char alphabet : inp) {
        if(current == alphabet) {
            counter++;
        } else {
            out = out + current + to_string(counter);
            counter = 1;
            current = alphabet;
        }
    }
    
    out = out + current + to_string(counter);
    cout<<out;

    return 0;
}

