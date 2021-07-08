#include <iostream>
#include <vector>

using namespace std;

bool isMatch(string s, string p) {
    vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));
    dp[0][0] = true;
    for(int i = 0; i < s.size()+1; i++){
        for(int j = 1; j < p.size()+1; j++){
            if (p[j - 1] == '*'){
                if (i > 0 && (p[j - 2] == '.' || s[i - 1] == p[j - 2])){
                    cout<<(dp[i][j - 2] || dp[i - 1][j])<<endl;
                    dp[i][j] = (dp[i][j - 2] || dp[i - 1][j]);
                }
                else
                    dp[i][j] = dp[i][j - 2];
            }
            else{
                if (i > 0 && (s[i - 1] == p[j -1]||p[j -1] == '.'))
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = false;
            }
        }
    }
    for (int i = 0; i <= s.size(); i++){
        for(int j = 0; j <= p.size(); j++){
            cout<<dp[i][j]<<' ';
        }
        cout<<endl;
    }
    return dp[s.size()][p.size()];
}

int main() {
    isMatch("aa","a*");
    return 0;
}
