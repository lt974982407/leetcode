#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool rec(TreeNode* root, int target ,int sum){
    if(!root)
        return false;
    sum = sum + root -> val;
    if (sum == target && !root -> left && !root -> right)
        return true;
    return rec(root -> left,target,sum) || rec(root -> right,target,sum);
}


bool hasPathSum(TreeNode* root, int targetSum) {
    return rec(root,targetSum,0);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
