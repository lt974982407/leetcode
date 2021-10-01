#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_map<int,int> m;
    for(int i = 0; i < nums.size(); i++){
        if(m[nums[i]] >= 1)
            return false;
        m[nums[i]]++;
    }
    return true;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
