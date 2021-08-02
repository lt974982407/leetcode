#include <iostream>
#include <vector>

using namespace std;

int maxValue(vector<vector<int>>& grid) {
    if(grid.size() == 0 || grid[0].size() == 0)
        return 0;
    int len1 = grid.size(),len2 = grid[0].size();
    vector<vector<int>> dp(len1,vector<int>(len2,0));
    dp[0][0] = grid[0][0];
    for(int i = 0; i < len1; i++){
        for (int j = 0; j < len2; j++){
            if(i == 0 && j == 0)
                continue;
            else if (i == 0){
                dp[i][j] = dp[i][j-1] + grid[i][j];
            }
            else if (j == 0)
                dp[i][j] = dp[i - 1][j] + grid[i][j];
            else
                dp[i][j] = max(dp[i -1][j],dp[i][j - 1]) + grid[i][j];
        }
    }
    return dp[len1 - 1][len2 -1 ];
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
