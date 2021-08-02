#include <iostream>

using namespace std;

int findNthDigit(int n) {
    int dig = 1;
    int index = 1;
    int tmp = 10;
    while (true){
        if(n - tmp >= 0)
            n -= tmp;
        else
            break;
        dig = dig * 10;
        index++;
        tmp = dig * 9 * index;
    }
    int num = n / index;
    int bit = n - num * index;
    int number ;
    if(dig!= 1)
        number = num + dig;
    else
        number = num;
    cout<< number <<endl;
    int res = 0;
    for(int i = 0;i < index - 1 - bit; i++ )
        number /= 10;
    res = number % 10;
    return res ;
}

int main() {
    std::cout << findNthDigit(1000000000) << std::endl;
    return 0;
}
