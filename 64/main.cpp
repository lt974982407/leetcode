#include <iostream>
#include <vector>

using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),0));
    dp[0][0] = grid[0][0];
    for(int i = 0; i < grid.size(); i++){
        for(int k = 0; k < grid[0].size();k++){
            if(i > 0 && k > 0)
                dp[i][k] = grid[i][k] + min(dp[i - 1][k],dp[i][k - 1]);
            else if(i > 0 && k == 0)
                dp[i][k] = grid[i][k] + dp[i - 1][k];
            else if(i == 0 && k > 0)
                dp[i][k] = grid[i][k] + dp[i][k - 1];
//            else
//                dp[i][k] = grid[i][k] ;
        }
    }
    return dp[grid.size()-1][grid[1].size()];
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
