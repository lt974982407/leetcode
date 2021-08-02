#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isStraight(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int num_0 = 0;
    for(int i = 0;i < nums.size() - 1; i++){
        if(nums[i] == 0)
            num_0++;
        else if(nums[i] == nums[i + 1])
            return false;
    }
    return nums[nums.size() - 1] - nums[num_0] < 5;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
