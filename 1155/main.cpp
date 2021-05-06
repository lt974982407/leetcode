#include <iostream>
#include <vector>

using namespace std;

int numRollsToTarget(int d, int f, int target) {
    vector<vector<int>> dp (target + 1,vector<int>(d + 1,0));
    dp[0][0] = 1;
    for (int i = 1; i <= target ; i++){
        for (int j = 1; j <= d; j++ ){
            for (int k = 1; k <= f ; k++){
                if (i - k >= 0){
                    dp[i][j] += dp[i - k][j -1];
                    dp[i][j] %= 1000000007;
                }
            }
        }
    }

    for (int i = 0; i <= target ; i++){
        for (int j = 0; j <= d; j++ ){
            cout<<dp[i][j]<<' ';
        }
        cout<<endl;
    }
    return dp[target][d];
}

int main() {
    cout<<numRollsToTarget(30,30,500);
    return 0;
}
