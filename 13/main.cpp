#include <iostream>
#include <unordered_map>

using namespace std;

int romanToInt(string s) {
    unordered_map<char,int> stan {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };
    int res = 0;
    for (int i = 0; i < s.size(); i++){
        if(i < s.size() - 1 && stan[s[i]] < stan[s[i + 1]]){
            res -= stan[s[i]];
        }
        else
            res += stan[s[i]];
    }
    return res;

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
