#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
    vector<int> count (32,0);
    for (int num: nums){
        for (int i = 0; i < 32; i++){
            count[i] += 1 & num;
            num >>= 1;
        }
    }
    int res = 0,tmp = 1;
    for(int i = 0; i < 32; i++){
        if((count[i] % 3) == 1){
            res +=tmp ;
        }
        if (i < 31)
            tmp <<= 1;
    }
    return res;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
