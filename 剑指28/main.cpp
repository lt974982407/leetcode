#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


bool dfs(TreeNode* p1, TreeNode* p2){
    if(!p1 || !p2)
        return !p1&&!p2;
    if(p1->val != p2->val)
        return false;
    return dfs(p1->left,p2->right) && dfs(p1->right,p2->left);
}

bool isSymmetric(TreeNode* root) {
    if(!root)
        return true;
    return dfs(root->left,root->right);

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
