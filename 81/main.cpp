#include <iostream>
#include <vector>

using namespace std;

bool search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while(l <= r ){
        int mid = (l + r) / 2;
        if(nums[mid] == target)
            return true;
        if(nums[l] == nums[mid])
            l++;
        else if(nums[l] < nums[mid]){
            if(nums[mid] > target && nums[l] <= target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        else{
            if(nums[mid] < target && nums[r] >= target)
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    return false;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
