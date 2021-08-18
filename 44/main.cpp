#include <iostream>
#include <vector>

using namespace std;

bool isMatch(string s, string p) {
    vector<vector<int>> dp(s.size() + 1,vector<int>(p.size() + 1,0));
    dp[0][0] = 1;
    for(int i = 0; i <= p.size(); i++){
        if(p[i - 1] == '*')
            dp[0][i] = 1;
        else
            break;
    }
    for(int i = 1; i <= s.size(); i++){
        for(int k = 1; k <= p.size(); k++){
            if(p[k - 1] != '?' && p[k - 1] != '*'){
                dp[i][k] = (s[i - 1] == p[k - 1]) && dp[i - 1][k - 1];
            }
            else if(p[k - 1] == '?')
                dp[i][k] = dp[i - 1][k - 1];
            else
                dp [i][k] = dp[i - 1][k] || dp[i][k - 1] || k == 1;
        }
    }
    return dp[s.size()][p.size()] == 1;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
