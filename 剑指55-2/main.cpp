#include <iostream>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int order(TreeNode* p){
    if (p == NULL)
        return 0;
    int left = order(p -> left);
    if(left == -1)
        return -1;
    int right = order(p -> right);
    if (right == -1)
        return -1;

    return (left - right < 2 && right - left < 2)? max(left,right) + 1 : -1;
}

bool isBalanced(TreeNode* root) {
    return order(root) != -1;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
