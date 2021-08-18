#include <iostream>
#include <vector>

using namespace std;

int firstMissingPositive(vector<int>& nums) {
    for(int i = 0 ; i < nums.size() ; i++){
        while(nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]){
            cout<<nums[i]<<' ' << nums[nums[i] - 1]<<endl;
            int tmp = nums[i];
            nums[i] = nums[nums[i] - 1];
            nums[tmp - 1] = tmp;
        }
    }
    for(int i = 0; i < nums.size(); i++){
        if(i + 1 != nums[i])
            return i + 1;
    }
    return nums.size() + 1;
}


int main() {
    vector<int> test = {3,4,-1,1};
    firstMissingPositive(test);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
