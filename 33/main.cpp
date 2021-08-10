#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(nums[mid] == target)
            return mid;
        if(nums[0] < nums[mid]){
            if(nums[l] <= target && nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        else{
            if(nums[r] >= target && nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    return -1;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
