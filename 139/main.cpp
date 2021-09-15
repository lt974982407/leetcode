#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> s1;
    unordered_set<int> s2;
    for(string index : wordDict){
        s1.insert(index);
        s2.insert(index.size());
    }
    vector<bool>dp (s.size() + 1);
    dp[0] = true;
    for(int i = 0; i < s.size(); i++){
        bool flag = false;
        for(unordered_set<int>::iterator it = s2.begin(); it != s2.end(); it++){
            if(i + 1 - *it >= 0){
                if(dp[i + 1 - *it] && s1.find(s.substr(i - *it,*it)) != s1.end())
                    flag = true;
            }
        }
        dp[i + 1] = flag;
    }
    return dp[s.size()];
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
