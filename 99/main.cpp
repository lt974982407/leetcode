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

void rec(TreeNode* p,TreeNode* pre,TreeNode*& x,TreeNode*& y ){
    if(!p)
        return;
    rec(p -> left, pre,x,y);
    if(pre && pre -> val > p -> val){
        if(!x && !y)
            x = pre;
        if(x && !y)
            y = p;
    }
    pre = p;
    rec(p -> right, pre,x,y);
}

void recoverTree(TreeNode* root) {
    TreeNode* pre = NULL, *x, * y;
    rec(root,pre,x,y);
    int tmp = x -> val;
    x -> val = y -> val;
    y -> val = tmp;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
