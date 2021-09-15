#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    res.push_back({1});
    for(int i = 1; i < numRows; i++){
        vector<int> tmp(i + 1,1);
        for(int j = 1; j < i;j ++){
            tmp[j] = res[i - 1][j - 1] + res[i - 1][j];
        }
        res.push_back(tmp);
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
