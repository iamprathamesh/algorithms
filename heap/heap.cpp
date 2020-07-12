i/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

void minHeapify(vector<int> &arr, int index, int length) {
    int leftIndex = 2*index + 1;
    int rightIndex = 2*index + 2;
    int minIndex = 0;
    
    if(leftIndex <= length && arr[leftIndex] < arr[index]) {
        minIndex = leftIndex;
    } else {
        minIndex = index;
    }
    
    if(rightIndex <= length && arr[rightIndex] < arr[minIndex]) {
        minIndex = rightIndex;
    }
    
    if(minIndex != index) {
        int temp = 0;
        temp = arr[index];
        arr[index] = arr[minIndex];
        arr[minIndex] = temp;
        minHeapify(arr, minIndex, length);
    }
    
}

void minHeap(vector<int> &arr) {
    int length = (arr.size()/2) - 1;
    for(int i=length; i>=0; i--) {
        minHeapify(arr, i, arr.size()-1);
    }
}

int main()
{
    vector<int> arr;
    
    arr.push_back(15);
    arr.push_back(5);
    arr.push_back(7);
    arr.push_back(20);
    arr.push_back(10);
    arr.push_back(12);
    arr.push_back(9);
    
    minHeap(arr);
    
    for(int data : arr) {
        cout<<" "<<data;
    }

    return 0;
}

