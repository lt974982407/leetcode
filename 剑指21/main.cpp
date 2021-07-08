#include <iostream>
#include <vector>

using namespace std;

vector<int> exchange(vector<int>& nums) {
    int i = 0,j = nums.size() - 1;
    while (i >= j){
        while((nums[i] % 2 != 0)&& i < j){
            i++;
        }
        while((nums[j] % 2 == 0)&& i < j){
            j --;
        }
        if (i < j){
            int tmp;
            tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
    }
    return nums;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
