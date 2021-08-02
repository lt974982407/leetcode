#include <iostream>

using namespace std;

string reverseLeftWords(string s, int n) {
    string res, tmp;
    for(int i = 0; i < n; i++)
        tmp += s[i];
    for (int i = n; i < s.size(); i++)
        res += s[i];
    res += tmp;
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
