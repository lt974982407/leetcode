#include <iostream>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int i = 0, j = 0;
    int res = 0;
    unordered_map<char,int> m;
    while(j < s.size()){
        int tmp = j - i;
        while(j < s.size() && m[s[j]] == 0){
            //cout<<'1'<<endl;
            tmp ++;
            m[s[j]]++;
            j++;
        }
        res = max(res,tmp);
        while (j < s.size() && m[s[j]] > 0){
            //cout<<'2'<<endl;
            m[s[i]]--;
            i++;
        }
    }
    return res;
}

int main() {
    std::cout << lengthOfLongestSubstring("dvdf") << std::endl;
    return 0;
}
