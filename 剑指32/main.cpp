#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> levelOrder(TreeNode* root) {
    if(root == NULL)
        return vector<int>(0);
    queue<TreeNode*> que;
    que.push(root);
    vector<int> res;
    while(!que.empty()){
        TreeNode* tmp = que.front();
        que.pop();
        res.push_back(tmp -> val);
        if(tmp->left)
            que.push(tmp->left);
        if(tmp->right)
            que.push(tmp->right);
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
