#include <iostream>
#include <vector>

using namespace std;

vector<double> dicesProbability(int n) {
    vector<vector<int>> dp (n + 1,vector<int>(6 * n + 1));
    dp[0][0] = 1;
    for(int i = 1; i < n + 1; i++){
        for(int k = 1; k <= 6 * n; k++){
            for(int j = 1; j <= 6 && k - j >= 0; j++)
                dp[i][k] += dp[i -1][k - j];
        }
    }
    vector<double> res;
    int sum = 0;
    for(int i = 0; i <= 6 * n; i++ ){
        sum += dp[n][i];
    }
    for(int i = 0; i <= 6 * n; i++ ){
        if(dp[n][i] != 0)
            res.push_back(1.0 * dp[n][i] / sum);
    }
    for(int i = 0; i < res.size(); i++ ){
        cout<<res[i]<<endl;
    }
    return res;
}

int main() {
    dicesProbability(2);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
