#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
    if(nums.size() == 0)
        return 0;
    //vector<int> dp(nums.size(),0);
    int dp1 = nums[0];
    int dp2;
    int maxnum = nums[0];
    for(int i = 1; i < nums.size(); i ++){
        dp2 = nums[i] + max(dp1,0);
        maxnum = max(maxnum,dp2);
        dp1 = dp2;
    }
    return maxnum;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
