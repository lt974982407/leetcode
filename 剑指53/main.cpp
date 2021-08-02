#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
    if(nums.size() == 0)
        return 0;
    int begin = 0, end = nums.size();
    while (begin < end){
        int mid = (begin + end) / 2;
        if(nums[mid] >= target)
            end = mid;
        else
            begin = mid + 1;
    }
    if(begin == nums.size() || nums[begin] != target)
        return 0;
    int res = 0;
    while(begin < nums.size() &&nums[begin] == target){
        res++;
        begin++;
    }
    return res;

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
