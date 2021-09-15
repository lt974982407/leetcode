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

int rec(TreeNode* root ,bool& flag){
    if(!root)
        return 0;
    int a = rec(root -> left,flag);
    int b = rec(root -> right, flag);
    if(a - b > 1 || a - b < - 1)
        flag = false;
    return max(a,b) + 1;
}

bool isBalanced(TreeNode* root) {
    bool res = false;
    rec(root, res);
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
