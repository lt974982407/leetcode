#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n) {
    if(n <= 2)
        return n;
    int pre1 = 1, pre2 = 2;
    for(int i = 3; i <= n; i++){
        int tmp = pre1;
        pre1 = pre2;
        pre2 = tmp + pre2;
    }
    return pre2;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
