#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int>& nums) {
    int begin = 0, end = nums.size() - 1;
    while(begin <= end){
        int mid = (begin + end) / 2;
        //cout<<mid<<endl;
        if((mid > 0 && nums[mid] < nums[mid - 1] ) )
            return nums[mid];
        if(nums[mid] == nums[begin]) {
            begin++;
            continue;
        }
        if(nums[begin] > nums[mid])
            end = mid - 1;
        else
            begin = mid + 1;
    }
    return nums[0];
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
