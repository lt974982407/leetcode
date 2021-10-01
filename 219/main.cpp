#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int,int> m;
    for(int i = 0; i < nums.size(); i++){
        if(m.find(nums[i]) != m.end()&& abs(i - m[nums[i]]) <= k)
            return true;
        else
            m[nums[i]] = i;
    }
    return false;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
