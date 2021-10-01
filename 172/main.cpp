#include <iostream>

using namespace std;

int trailingZeroes(int n) {
    int res = 0;
    while (n > 0){
        n = n / 5;
        res = res + n;
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
