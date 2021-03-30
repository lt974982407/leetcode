#include <iostream>
#include <vector>

using namespace std;


bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.size() == 0 || matrix[0].size() == 0) return false;
    int i = 1, row = matrix.size(), col = matrix[0].size();
    for (; i < row; i++ ){
        if(matrix[i-1][0] <= target && matrix[i][0] > target)
            break;
    }
    for (int j = 0; j < col ; j++){
        if (matrix[i -1][j] == target)
            return true;
    }
    return false;
}

int main() {
    vector<vector<int>> s = {{1,3,4,7},{8,9,10,11},{12,14,16,20},{21,23,34,56}};
    cout << searchMatrix(s,12) << std::endl;
    return 0;
}
