#include <iostream>

using namespace std;


double quickmul(double x, long long n){
    double res = 1.0;
    double index = x;
    while(n > 0){
        if(n % 2 != 0)
            res = res * index;
        index = index * index;
        n = n / 2;
    }
    return res;
}

double myPow(double x, int n) {
   long long t = n;
   if(t >= 0)
       return quickmul(x,n);
   else
       return 1 / quickmul(x,-n);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
