#include <iostream>
#include <vector>

using namespace std;

int countPrimes(int n) {
    if(n <= 2)
        return 0;
    int res = 0;
    vector<bool> arr(n ,true);
    for(int i = 2; i < n; i ++){
        if(arr[i]){
            res ++;
            if ((long long)i * i < n) {
                for (int j = i * i; j < n; j = j + i) {
                    arr[j] = false;
                }
            }
        }
    }
    return res;
}

int main() {
    countPrimes(10);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
