#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    unordered_map<string ,int> strmap;
    int cnt = 1;
    for(string str : strs){
        string tmp = str;
        sort(tmp.begin(),tmp.end());
        if(strmap[tmp] == 0){
            strmap[tmp] = cnt;
            res.push_back({str});
            cnt++;
        } else
            res[strmap[tmp] - 1].push_back(str);
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
