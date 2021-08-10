#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int l = 0, r = nums.size();
    while(l < r){
        int mid = (l + r) / 2;
        if(nums[mid] >= target )
            r = mid;
        else
            l = mid + 1;
    }
    if(l == nums.size() || nums[l] != target)
        return {-1,-1};
    vector<int> res (2,l);
    while(l < nums.size() && nums[l] == target)
        l++;
    res[1] = l - 1;
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
