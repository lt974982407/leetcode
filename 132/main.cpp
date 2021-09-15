#include <iostream>
#include <vector>

using namespace std;

int minCut(string s) {
    vector<vector<bool>> dp(s.size(),vector<bool> (s.size()));
    for(int j = 0; j < s.size(); j++){
        for(int i = 0; i <= j; i ++){
            if(i == j)
                dp[i][j] = true;
            else if (j - i == 1)
                dp[i][j] = s[i] == s[j];
            else
                dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
        }
    }
    vector<int> dp1(s.size() + 1,INT_MAX);
    dp1[0] = 0;
    for(int i = 0; i < s.size(); i++){
        for(int j = i; j >= 0; j--){
            if(dp[j][i]){
                dp1[i + 1] = min(dp1[i + 1],dp1[j - 1] + 1);
            }
        }
    }
    return dp1[s.size()];
}

int main() {
    cout<<minCut("abacca");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
