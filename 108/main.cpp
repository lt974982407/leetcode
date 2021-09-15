#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* rec(vector<int> nums, int begin , int end){
    if(begin > end)
        return nullptr;
    int mid = (begin + end) / 2;
    TreeNode* p = new TreeNode (nums[mid]);
    p -> left = rec(nums,begin,mid - 1);
    p -> right = rec(nums,mid + 1, end);
    return p;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return rec(nums,0,nums.size() - 1);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
