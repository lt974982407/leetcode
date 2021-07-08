#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* mirrorTree(TreeNode* root) {
    if(!root)
        return NULL;
    queue<TreeNode*> que;
    queue<TreeNode*> que1;
    TreeNode* head = new TreeNode(root -> val);
    que.push(root);
    que1.push(head);
    while(!que.empty()){
        TreeNode* tmp = que.front();
        TreeNode* tmp1 = que1.front();
        que.pop();
        que1.pop();
        if(tmp->right) {
            tmp1->left = new TreeNode(tmp->right->val);
            que.push(tmp->right);
            que1.push(tmp1->left);
        }
        if(tmp->left) {
            tmp1->right = new TreeNode(tmp->left->val);
            que.push(tmp->left);
            que1.push(tmp1->right);
        }
    }
    return head;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
