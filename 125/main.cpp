#include <iostream>

using namespace std;

bool isPalindrome(string s) {
    int begin = 0, end = s.size() - 1;
    while (begin <= end){
        if(!(s[begin] >= 'A' && s[begin] <= 'Z'||s[begin] >= 'a' && s[begin] <= 'z' || s[begin] >= '0' && s[begin] <='9')) {
            begin++;
            continue;
        }
        if(!(s[end] >= 'A' && s[end] <= 'Z'||s[end] >= 'a' && s[end] <= 'z'|| s[end] >= '0' && s[end] <='9')) {
            end--;
            continue;
        }
        if(!(s[begin] == s[end] || (s[begin] >= 'A' && s[begin] <= 'Z' && s[begin] - 'A' + 'a' == s[end]) || (s[begin] >= 'a' && s[begin] <= 'z' && s[begin] - 'a' + 'A' == s[end])))
            return false;
        begin ++;
        end --;
    }
    return true;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
