#include <iostream>

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void preorder(TreeNode* p,int k,int& res){
    if(p != NULL){
        preorder(p -> right,k,res);
        if (k == 1)
            res =  p -> val;
        k--;
        preorder(p-> left,k,res);
    }
}

int kthLargest(TreeNode* root, int k) {
    int res = 0;
    preorder(root,k,res);
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
