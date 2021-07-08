#include <iostream>

using namespace std;

double myPow(double x, int n) {
    double res = 1;
    if(abs(x-0.0) < 1e-8){
        return 0.0;
    }
    if(n == 0)
        return 1;
    long exp = long(n);
    if (n < 0){
        x = 1 / x;
        exp = - exp;
    }
    while(exp){
        if(exp & 1 == 1)
            res *= x;
        x *= x;
        exp >>= 1;
    }
    return res;

}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
