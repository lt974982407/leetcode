#include <iostream>

#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
    int res = 0;
    for(int num : nums)
        res = res ^ num;
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
