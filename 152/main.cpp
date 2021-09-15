#include <iostream>
#include <vector>

using namespace std;

int maxProduct(vector<int>& nums) {
    int res = nums[0], pre1 = nums[0],pre2 = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        pre1 = max(pre1 * nums[i], max(pre2 * nums[i],nums[i]));
        pre2 = min(pre1 * nums[i], min(pre2 * nums[i],nums[i]));
        res = max(pre1,res);
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
