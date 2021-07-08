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

vector<vector<int>> levelOrder(TreeNode* root) {
    if(root == NULL)
        return vector<vector<int>>(0);
    vector<vector<int>>  res;
    queue<TreeNode*> que;
    que.push(root);
    bool flag = true;
    while (!que.empty()){
        vector<int> tmpval;
        int len = que.size();
        for (int i = 0; i < len; i++){
            TreeNode* tmp = que.front();
            que.pop();
            if(flag)
                tmpval.push_back(tmp -> val);
            else
                tmpval.insert(tmpval.begin(),tmp->val);
            if(tmp->left)
                que.push(tmp -> left);
            if(tmp -> right)
                que.push(tmp -> right);
        }
        flag = !flag;
        res.push_back(tmpval);
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
