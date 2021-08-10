#include <iostream>

using namespace std;

int strStr(string haystack, string needle) {
    int len1 = haystack.size(), len2 = needle.size();
    if(len2 == 0)
        return 0;
    for(int i = 0; i <= len1 - len2; i++){
        int k;
        for( k = 0; k < len2; k++)
            if(haystack[k + i] != needle[k])
                break;
        if(k == len2)
            return i;
    }
    return -1;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
