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

void rec(TreeNode* p, long long& num,bool& flag ){
    if(!p)
        return ;
    rec(p -> left,num,flag);
    if(p -> val <= num) {
        flag = false;
        return ;
    }
    num = p -> val;
    rec(p -> right,num,flag);
}

bool isValidBST(TreeNode* root) {
    long long num = -2147483648 - 1;
    bool flag = true;
    rec(root,num,flag);
    return flag;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
