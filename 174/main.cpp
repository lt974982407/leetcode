#include <iostream>
#include <vector>

using namespace std;

//常规的想法为dp[i][j]表示起点到(i,j)的最小需求
//但是这样做变量太多，不好控制
//从终点到起点dp

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    vector<vector<int>> dp(dungeon.size() + 1,vector<int>(dungeon[0].size() + 1,INT_MAX));
    dp[dungeon.size()][dungeon[0].size() - 1] = 1;
    dp[dungeon.size() - 1][dungeon[0].size() ] = 1;
    for(int i = dungeon.size() - 1; i >= 0; i--){
        for(int j = dungeon[0].size() - 1; j >= 0; j--){
            dp[i][j] = max(min(dp[i + 1][j],dp[i][j + 1]) - dungeon[i][j] , 1);
        }
    }

    return dp[0][0];
}

int main() {
    vector<vector<int>> test = {{1,-3,3},{0,-2,0},{-3,-3,-3}};
    calculateMinimumHP(test);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
