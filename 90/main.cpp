#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rec(vector<vector<int>>& res, int index ,int cnt,vector<int> tmp,vector<int> nums){
    if(tmp.size() == cnt){
        res.push_back(tmp);
        return;
    }
    for(int i = index; i < nums.size(); i++){
        if(i > index && nums[i] == nums[i - 1])
            continue;
        tmp.push_back(nums[i]);
        rec(res,i + 1, cnt , tmp,nums);
        tmp.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int>> res;
    for(int i = 1; i <= nums.size(); i++){
        rec(res,0,i,{},nums);
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
