#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(vector<int>& nums) {
    int begin = 0, end = nums.size() - 1;
    while(begin <= end){
        int mid = (begin + end) / 2;
        if(mid == 0 ){
            if( nums.size() == 1 || nums[mid] > nums[mid + 1])
                return 0;
            else{
                begin ++;
                continue;
            }
        }
        if(mid == nums.size() - 1 ){
            if(nums[nums.size() - 1] > nums[nums.size() - 2]){
                return nums.size() - 1;
            }
            else{
                end --;
                continue;
            }
        }
        if(nums[mid] > nums[mid + 1] && nums[mid] > nums[mid + 1])
            return mid;
        if(nums[mid] < nums[mid - 1])
            end = mid;
        else
            begin = mid;
    }
    return 0;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
