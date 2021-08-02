#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left <= right){
        int mid = (left + right) / 2;
        if (nums[mid] == mid)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
