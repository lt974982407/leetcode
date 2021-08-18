#include <iostream>
#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp (m,vector<int>(n,1));
    bool flag = false;
    for(int i = 0; i < m; i++)
        if(flag || obstacleGrid[i][0] == 1) {
            dp[i][0] = 0;
            flag = true;
        }
        else
            dp[i][0] =  1;
    flag = false;
    for(int i = 0; i < n; i++)
        if(flag || obstacleGrid[0][i] == 1) {
            dp[0][i] = 0;
            flag = true;
        }
        else
            dp[0][i] =  1;
//    for(int i = 0 ;i < m ;i++){
//        for(int k = 0; k < n; k++){
//            cout<<dp[i][k]<<' ';
//        }
//        cout<<endl;
//    }
    for(int i = 1; i < m; i++){
        for(int k = 1; k < n; k ++){
            if(obstacleGrid[i][k] == 1)
                dp[i][k] = 0;
            else
                dp[i][k] = dp[i - 1][k] + dp[i][k - 1];
        }
    }
    return dp[m-1][n-1];
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
