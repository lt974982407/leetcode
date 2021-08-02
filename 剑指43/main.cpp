#include <iostream>

using namespace std;

int countDigitOne(int n) {
    int high = n / 10;
    int curr = n % 10;
    int low = 0;
    int dig = 1;
    int res = 0;
    while(curr != 0 || high != 0){
        if (curr == 0){
            res += dig * high;
        }
        else if (curr == 1){
            res += (dig * high + low + 1);
        }
        else{
            res += (dig + 1) * dig;
        }
        low = low + curr * dig;
        curr = high % 10;
        high = high / 10;
        dig = dig * 10;
    }
    return res;
}

int main() {
    std::cout << countDigitOne(20) << std::endl;
    return 0;
}
