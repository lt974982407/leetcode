#include <iostream>
#include <cmath>
using namespace  std;

bool isPalindrome(int x) {
    if (x<0 || x%10==0 && x!=0) return false;
    int reverse = 0;
    while (reverse < x){
        reverse = reverse * 10 + x%10;
        x = x /10;
    }
    cout<< x << ' '<< reverse<<endl;
    return x==reverse || x==reverse/10;
}
int main() {
    std::cout << isPalindrome(121) << std::endl;
    return 0;
}
