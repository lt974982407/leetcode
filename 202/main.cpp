#include <iostream>
#include <unordered_set>

using namespace std;

bool isHappy(int n) {
    unordered_set<int> s;
    while(s.find(n) == s.end()){
        s.insert(n);
        int tmp = 0;
        while(n){
            tmp = tmp + (n % 10) * (n % 10);
            n = n / 10;
        }
        if(tmp == 1)
            return true;
        n = tmp;
    }
    return false;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
