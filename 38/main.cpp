#include <iostream>
#include <vector>

using namespace std;

string countAndSay(int n) {
    if(n == 1)
        return "1";
    string s = countAndSay(n - 1);
    string res = "";
    int tmp = 1;
    char c = s[0];
    for(int i = 1; i < s.size(); i++){
        if(s[i] == s[i - 1])
            tmp++;
        else{
            res += to_string(tmp);
            res += c;
            tmp = 1;
            c = s[i];
        }
    }
    res += to_string(tmp);
    res += s[s.size() - 1];
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
