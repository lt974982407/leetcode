#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    if(nums.size() == 0)
        return res;
    sort(nums.begin(),nums.end());
    for(int i = 0; i < nums.size() - 2;i ++){
        if(nums[i] > 0)
            break;
        if(i > 0 && nums[i] == nums[i - 1])
            continue;
        int begin = i + 1, end = nums.size() - 1;
        while(begin < end){
            if(nums[i] + nums[begin] + nums[end] < 0)
                begin ++;
            else if(nums[i] + nums[begin] + nums[end] > 0)
                end --;
            else{
                res.push_back({nums[i],nums[begin],nums[end]});
                begin ++;
                while(begin < end && nums[begin] == nums[begin + 1])
                    begin ++;
                end --;
                while(begin < end && nums[end] == nums[end - 1])
                    end --;
            }
        }
    }
    return res;
}

int main() {
    vector<int> test = {{0}};
    threeSum(test);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
