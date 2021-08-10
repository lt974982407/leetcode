#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int res = nums[0] + nums[1] + nums[2];
    for(int i = 0; i < nums.size() - 2; i++){
        int begin = i + 1, end = nums.size() - 1;
        while(begin < end){
            int sum = nums[i] + nums[begin] + nums[end];
            res = abs(sum - target) < abs(res - target) ? sum : res;
            if(sum < target)
                begin ++;
            else if(sum > target)
                end --;
            else
                return target;
        }
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
