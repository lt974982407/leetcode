#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if(matrix.size() == 0)
        return vector<int>(0);
    int len1 = matrix.size(),len2 = matrix[0].size();
    int len = len1*len2;
    int top = 0,bot = len1 - 1,left = 0, right = len2 - 1;
    vector<int> res;
    int tp = 0;
    while(tp < len){
        for(int i = left ;i <= right && tp < len; i++){
            res.push_back(matrix[top][i]);
            tp ++;
        }
        top ++;
        for(int i = top ;i <= bot && tp < len; i++){
            res.push_back(matrix[i][right]);
            tp++;
        }
        right --;
        for(int i = right ;i >= left&& tp < len; i--){
            res.push_back(matrix[bot][i]);
            tp++;
        }
        bot --;
        for(int i = bot ;i >= top&& tp < len; i--){
            res.push_back(matrix[i][left]);
            tp++;
        }
        left++;
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
