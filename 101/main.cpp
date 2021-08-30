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

bool rec(TreeNode* a,TreeNode* b){
    if( !a && !b)
        return true;
    if(!a || !b)
        return false;
    return a -> val == b -> val && rec(a->left,b -> right) && rec(a -> right, b -> left);
}

bool isSymmetric(TreeNode* root) {
    return rec(root,root);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
