#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
    int res = 0;
    for(int i = 0; i < 32; i++){
        int cnt = 0;
        for(int num : nums)
            cnt = cnt + ((num >> i) & 1);
        if(cnt % 3)
            res = res | (1 << i);
    }
    return res;

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
