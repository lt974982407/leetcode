#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int>& nums) {
    int maxpos = 0;
    for(int i = 0; i < nums.size() - 1; i++){
        if(i <= maxpos){
            maxpos = max(maxpos,i + nums[i]);
            if(maxpos >= nums.size() - 1)
                return true;
        }
    }
    return false;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
