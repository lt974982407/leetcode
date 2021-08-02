#include <iostream>
#include <vector>

using namespace std;

vector<int> singleNumbers(vector<int>& nums) {
    int n = 0;
    for(int num : nums)
        n = n ^ num;
    int m = 1;
    while((n & m) == 0)
        m <<= 1;
    int x = 0, y = 0;
    for (int num : nums)
        if((num & m))
            x ^= num;
        else
            y ^= num;
    return vector<int> {x,y};
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
