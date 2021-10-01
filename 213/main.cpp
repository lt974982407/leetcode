#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums) {
    if(nums.size() == 1)
        return nums[0];
    if(nums.size() == 2)
        return max(nums[0],nums[1]);
    vector<int> dp(nums.size() ,0);
    dp[0] = nums[0];
    nums[1] = max(nums[0],nums[1]);
    for(int i = 2; i < nums.size() - 1; i++){
        dp[i] = max(nums[i] + dp[i - 2] , dp[i - 1]);
    }
    int res = dp[nums.size() - 2];
    dp[1] = nums[1];
    dp[2] = max(nums[2],nums[1]);
    for(int i = 3; i < nums.size();i++){
        dp[i] = max(nums[i] + dp[i - 2] , dp[i - 1]);
    }
    res = max (res, dp[nums.size() - 1]);
    return res;

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
