#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    if(nums.size() == 0)
        return 0;
    int i = 0, j = 1;
    while(j < nums.size()){
        if(nums[i] == nums[j])
            j++;
        else{
            i++;
            nums[i] = nums[j];
        }
        j++;
    }
    return i + 1;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
