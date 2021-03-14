#include <iostream>
#include <vector>

using namespace  std;

int maxArea(vector<int>& height) {
    int ans = 0, len = height.size();
    for (int i = 0; i < len;i ++){
        for (int k = i + 1;k < len; k++){
            int tmp = (k - i)* min(height[i],height[k]);
            ans = tmp > ans ? tmp :ans;
        }
    }
    return ans;

}

int main() {
    vector<int> s = {4,3,2,1,4};
    std::cout << maxArea(s) << std::endl;
    return 0;
}
