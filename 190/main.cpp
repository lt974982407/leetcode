#include <iostream>

using namespace std;

uint32_t reverseBits(uint32_t n) {
    int res = 0;
    for(int i = 0; i < 32; i++){
        res = res | ((n >> (31 - i)) & 1) << i;
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
