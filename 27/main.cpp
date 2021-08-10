#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    int i = 0, j = 0;
    while(j < nums.size()){
        if(nums[j] == val){
            nums[i] = nums[j];
            i++;
        }
        j++;
    }
    return i + 1;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
