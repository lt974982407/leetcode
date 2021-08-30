#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void rec(vector<int>& res, TreeNode* root){
    if(!root)
        return;
    rec(res,root -> left);
    res.push_back(root -> val);
    rec(res,root -> right);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    rec(res,root);
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
