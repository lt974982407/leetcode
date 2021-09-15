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

void rec(int& res, int tmp,TreeNode* root){
    if(!root)
        return;
    tmp = tmp * 10 + root ->  val;
    if(!root -> left && !root -> right){
        res = res + tmp;
        return;
    }
    rec(res,tmp,root -> left);
    rec(res,tmp,root -> right);
}

int sumNumbers(TreeNode* root) {
    int res = 0;
    rec(res,0,root);
    return res;
}



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
