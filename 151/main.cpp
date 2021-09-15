#include <iostream>

using namespace std;

string reverseWords(string s) {
    s += ' ';
    string res = "";
    string tmp = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' ' && !tmp.empty()){
            res = res + tmp +' ';
            tmp.clear();
            continue;
        }
        tmp = tmp + s[i];
    }
    res.pop_back();
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
