#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int x, int y){
    int x1 = 10, y1 = 10;
    while(x1 <= x)
        x1 *= 10;
    while(y1 <= y)
        y1 *= 10;
    return x * y1 + y > y * x1 + x;
}

string largestNumber(vector<int>& nums) {
    sort(nums.begin(),nums.end(), cmp);
    string res = "";
    if(nums[0] == 0)
        return "0";
    for(int i = 0; i < nums.size();i++)
        res = res + to_string(nums[i]);
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
