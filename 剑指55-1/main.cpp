#include <iostream>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void order(TreeNode* p, int& res, int dep){
    if (p == NULL){
        res = max(res, dep);
        return;
    }
    dep++;
    order(p -> left, res,dep);
    order(p -> right,res,dep);
}

int maxDepth(TreeNode* root) {
    int res = 0;
    order(root, res, 0);
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
