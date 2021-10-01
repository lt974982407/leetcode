#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    set<int> s;
    for(int i = 0; i < nums.size(); i++){
        set<int>::iterator it = s.lower_bound(max(nums[i],INT_MIN + t) - t);
        if(it != s.end() && *it <= min(nums[i],INT_MAX - t) + t)
            return true;
        s.insert(nums[i]);
        if(i - k >= 0)
            s.erase(nums[i - k]);
    }
    return false;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
