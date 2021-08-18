#include <iostream>
#include <vector>

using namespace std;

int trap(vector<int>& height) {
    int left = 0,right = height.size() - 1;
    int lheight = 0, rheight = 0;
    int res = 0;
    while(left <= right){
        lheight = max(height[left],lheight);
        rheight = max(height[right],rheight);
        if(lheight < rheight){
            res = res + lheight - height[left];
            left++;
        }
        else{
            res = res + rheight - height[right];
            right --;
        }
    }
    return res;
}

int main() {
    vector<int> test = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trap(test)<<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
