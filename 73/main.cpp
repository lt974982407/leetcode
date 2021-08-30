#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    bool col = false, row = false;
    for(int i = 0; i < matrix.size(); i++)
        if(!matrix[i][0])
            col = true;
    for(int j = 0; j < matrix[0].size(); j++)
        if(!matrix[0][j])
            row = true;
    for(int i = 1; i < matrix.size(); i++){
        for(int j = 1; j < matrix[0].size(); j++){
            if(!matrix[i][j]){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for(int i = 1; i < matrix.size(); i++){
        for(int j = 1; j < matrix[0].size(); j++){
            if(!matrix[i][0] || !matrix[0][j]){
                matrix[i][j] = 0;
            }
        }
    }
    if(col){
        for(int i = 0; i < matrix.size();i++)
            matrix[i][0] = 0;
    }
    if(row){
        for(int i = 0; i < matrix[0].size();i++)
            matrix[0][i] = 0;
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
