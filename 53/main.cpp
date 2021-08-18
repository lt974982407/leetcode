#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int res = nums[0];
    int pre = -1;
    for(int num : nums){
        if(pre <= 0)
            pre = num;
        else
            pre = pre + num;
        res = max(pre,res);
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
