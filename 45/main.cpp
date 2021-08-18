#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int>& nums) {
    int res = 0, maxp = 0,end = 0;
    for(int i = 0; i < nums.size() - 1; i++){
        maxp = max(maxp,nums[i] + i);
        if(i == end){
            end = maxp;
            res ++;
        }
    }
    return res;
}

int main() {
    vector<int> test = {2,0,0,0,3};
    cout<<jump(test)<<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
