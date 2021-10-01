#include <iostream>

using namespace std;

int titleToNumber(string columnTitle) {
    int res = 0;
    for(char c : columnTitle){
        int tmp = c - 'A' + 1;
        res = res * 26 + tmp;
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
