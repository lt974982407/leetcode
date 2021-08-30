#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int res = 0,cnt = 0;
    for(int i = 0; i < nums.size(); i++){
        if(i > 0 && nums[i] == nums[i - 1]){
            cnt++;
            if(cnt < 2){
                nums[res] = nums[i];
                res++;
            }
        }
        else{
            nums[res] = nums[i];
            res++;
            cnt = 0;
        }
    }
    return res - 1;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
