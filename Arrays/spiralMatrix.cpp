#include <iostream>
#include <vector>

using namespace std;

void convertToSpiral(vector< vector<int> > &data) {
    int top = 0;
    int bottom = data.size()-1;
    int left = 0;
    int right = data[0].size()-1;
    int dir = 0;
    
    while(top <= bottom && left <= right) {
        if(dir == 0) {
            for(int i=left; i<=right; i++) {
                cout<<data[top][i]<<" ";
            }
            top++;
            dir = 1;
        } else if(dir == 1) {
            for(int i=top; i<=bottom; i++) {
                cout<<data[i][right]<<" ";
            }
            right--;
            dir = 2;
        } else if(dir == 2) {
            for(int i=right; i>=left; i--) {
                cout<<data[bottom][i]<<" ";
            }
            bottom--;
            dir = 3;
        } else if(dir == 3) {
            for(int i=bottom; i>=top; i--) {
                cout<<data[i][left]<<" ";
            }
            left++;
            dir = 0;
        }
    }
}

int main() {
    
    vector< vector<int> > data;
    vector<int> row;
    
    row.push_back(10);
    row.push_back(20);
    row.push_back(30);
    row.push_back(40);
    
    data.push_back(row);
    data.push_back(row);
    data.push_back(row);
    data.push_back(row);
    
    convertToSpiral(data);
    
    return 0;
}
