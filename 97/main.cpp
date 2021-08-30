#include <iostream>
#include <vector>

using namespace std;

bool isInterleave(string s1, string s2, string s3) {
    //vector<vector<vector<bool>>> dp (s1.size() + 1,vector<vector<bool>>(s2.size() + 1,vector<bool>(s3.size() + 1, false)));
    if(s1.size() + s2.size() != s3.size())
        return false;
    vector<vector<bool>> dp(s1.size(),vector<bool>(s2.size(), false));
    dp[0][0] = true;
    for(int i = 0 ; i <= s1.size(); i++){
        for(int j = 0; j <= s2.size();j++){
            if(i == 0 && j == 0)
                continue;
            dp[i][j] = (i > 0 && s1[i - 1] == s3[i + j - 2] && dp[i - 1][j]) || (j > 0 && s2[j - 1] == s3[i + j - 2] && dp[i][j - 1]);
        }
    }
    return dp[s1.size()][s2.size()];
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
