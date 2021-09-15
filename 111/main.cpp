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

int rec(TreeNode* root){
    if(!root)
        return 0;
    if(!root -> left && !root -> right)
        return 1;
    int res = 0,l = rec(root -> left), r = rec(root -> right);
    if(l == 0)
        res = r + 1;
    else if(r == 0)
        res = l + 1;
    else
        res = min(l, r) + 1;
    return res;
}

int minDepth(TreeNode* root) {
    return rec(root);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
