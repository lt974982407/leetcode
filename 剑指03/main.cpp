#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int findRepeatNumber(vector<int>& nums) {
    unordered_set<int> s;
    for (int i = 0; i < nums.size();i++){
        if(s.find(nums[i]) == s.end()){
            s.insert(nums[i]);
        }
        else
            return nums[i];
    }
    return -1;
}

int findRepeatNumber1(vector<int>& nums) {
    for (int i = 0;i < nums.size();i++){
        while (nums[i] != i){
            if (nums[i] == nums[nums[i]])
                return nums[i];
            else{
                int tmp = nums[i];
                nums[i] = nums[tmp];
                nums[tmp] = tmp;
            }
        }
    }
    return -1;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
