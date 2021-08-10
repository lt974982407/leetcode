#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if(strs.size() == 0)
        return "";
    if(strs.size() == 1)
        return strs[0];
    int len = strs[0].size() - 1;
    for(int i = 1; i < strs.size(); i++){
        int k = 0;
        for(; k < strs[i].size() && k <= len; k++){
            if(strs[i][k] != strs[0][k] )
                break;
        }
        len = min(len,k - 1);
        if(len == -1)
            return "";
    }
    return strs[0].substr(0,len);
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
