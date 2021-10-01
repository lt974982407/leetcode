#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using namespace std;

void rec(TreeNode* a, TreeNode* b){
    if(a -> left){
        b -> right = new TreeNode (a -> left -> val);
        rec(a -> left, b -> right);
    }
    if(a -> right){
        b -> left = new TreeNode(a -> right -> val);
        rec(a -> right,b -> left);
    }
}


TreeNode* invertTree(TreeNode* root) {
    if(!root)
        return nullptr;
    TreeNode* res = new TreeNode (root -> val);
    rec(root,res);
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
