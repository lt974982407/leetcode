#include <iostream>
#include <string>
#include <vector>
using namespace  std;

bool isMatch(string s, string p) {
    int slen = s.size();
    int plen = p.size();
    vector <vector<bool>> dp (slen + 1, vector<bool>(plen + 1,false));
    dp[0][0] = true;
    for (int i = 0; i <= slen; i++){
        for (int k = 1; k <= plen; k++){
            if (p[k-1] != '*'){
                if (i!= 0 &&(p[k-1] == s[i-1] || p[k-1] == '.'))
                    dp[i][k] = dp[i - 1][k - 1];
                else dp[i][k] = false;
            }
            else{
                if(i != 0 &&(p[k-2] == s[i-1] || p[k-2] == '.'))
                    dp[i][k] = dp[i-1][k] || dp[i][k-2];
                else
                    dp[i][k] = dp[i][k-2];
            }

        }
    }
    /*for (int i = 0 ; i <=slen; i++){
        for (int k = 0; k <= plen; k++){
            cout<<dp[i][k]<<' ';
        }
        cout<<endl;
    }*/
    return dp[slen][plen];
}

int main() {
    std::cout << isMatch("aa","a") << std::endl;
    return 0;
}
