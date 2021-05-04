#include <iostream>
#include <vector>
using namespace std;

bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    if(matrix.size() == 0 || matrix[0].size() == 0) return false;
    int row = 0, col = matrix[0].size() - 1;
    while (row < matrix.size() && col >= 0){
        if (matrix[row][col] == target)
            return true;
        else if(matrix[row][col] < target)
            row++;
        else
            col--;
    }
    return false;
}


int main() {
    vector<vector<int>> s = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24},{ 18, 21, 23, 26, 30 } };
    std::cout << findNumberIn2DArray(s,20) << std::endl;
    return 0;
}
