#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int majorityElement(vector<int>& nums) {
    unordered_map <int,int> ht;
    for(int i = 0; i < nums.size(); i++){
        ht[nums[i]]++;
        if(ht[nums[i]] > nums.size()/2)
            return nums[i];
    }
    return 0;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
