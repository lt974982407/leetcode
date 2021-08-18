#include <iostream>
#include <vector>

using namespace std;

void rec(int& res,int m,int n,int row,int col){
    if(col == m && row == n){
        res++;
        return;
    }
    else if(col > m || row > n)
        return;
    rec(res,m,n,row + 1,col);
    rec(res,m,n,row,col + 1);
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp (m,vector<int>(n,1));
    for(int i = 1; i < m; i++){
        for(int k = 1; k < n; k ++){
            dp[i][k] = dp[i - 1][k] + dp[i][k - 1];
        }
    }
    return dp[m-1][n-1];
}

int main() {
    cout<<uniquePaths(7,3)<<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
