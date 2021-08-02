#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    if(nums.size() <= 1)
        return vector<int> (0);
    int i = 0, j = nums.size() - 1;
    while (i < j){
        if(nums[i] + nums[j] == target){
            return vector<int> {nums[i],nums[j]};
        }
        else if (nums[i] + nums[j] > target){
            j--;
        }
        else{
            i++;
        }
    }
    return vector<int> (0);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
