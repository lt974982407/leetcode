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

bool rec(TreeNode* a, TreeNode* b){
    if(!a &&!b)
        return true;
    if(!a || !b)
        return false;
    if(a -> val == b -> val)
        return rec(a -> left,b-> left) && rec(a -> right,b -> right);
    else
        return false;
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    return rec(p,q);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
