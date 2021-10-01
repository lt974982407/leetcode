#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int>& nums) {
    while(true){
        int random = nums[rand()% (nums.size())];
        int cnt = 0;
        for(int num : nums)
            if(num == random)
                cnt++;
        if(cnt > nums.size() / 2)
            return random;
    }
    return - 1;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
