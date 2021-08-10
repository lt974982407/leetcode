#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    vector<vector<int>> res;
    for(int i = 0; i + 3 < nums.size(); i++){
        if(nums[i] > target && nums[i] > 0)
            return res;
        if(i > 0 && nums[i] == nums[i -1])
            continue;
        for(int k = i + 1; k + 2 < nums.size(); k++){
            //cout<<k<<endl;
            if(k > i + 1 && nums[k] == nums[k -1])
                continue;
            int begin = k + 1, end = nums.size() - 1;
            while(begin < end){
                int sum = nums[i] + nums[k] + nums[begin] + nums[end];
                if(sum > target)
                    end--;
                else if(sum < target)
                    begin++;
                else{
                    res.push_back({nums[i],nums[k],nums[begin],nums[end]});
                    do{
                        begin++;
                    }while(begin < end && nums[begin] == nums[begin - 1]);
                    do{
                        end--;
                    }while(begin < end && nums[end] == nums[end + 1]);
                }
            }
        }
    }
    return res;
}

int main() {
    vector<int> test = {2,2,2,2};
    fourSum(test,8);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
