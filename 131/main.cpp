#include <iostream>
#include <vector>

using namespace std;

void rec(vector<vector<string>>& res,vector<vector<bool>> dp,int index,vector<string> tmp,string s){
    if(index == s.size()){
        res.push_back(tmp);
        return;
    }
    for(int i = index; i < s.size(); i++){
        if(dp[index][i]){
            tmp.push_back(s.substr(index,i - index + 1));
            rec(res,dp,i + 1,tmp,s);
            tmp.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
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
    for(int j = 0; j < s.size(); j++){
        for(int i = 0; i <= j; i ++){
            cout << dp[i][j]<<' ';
        }
        cout<<endl;
    }
    vector<vector<string>> res;
    rec(res,dp,0,{},s);
    //cout<<res.size()<<endl;
    return res;
}

int main() {
    partition("aab");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
