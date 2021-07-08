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
    if (root = NULL)
        return vector<vector<int>>(0);
    vector<vector<int>> res;
    queue<queue<TreeNode*>> que;
    queue<TreeNode*> tmp;
    tmp.push(root);
    que.push(tmp);
    while(!que.empty()){
        queue<TreeNode*> temp = que.front();
        que.pop();
        queue<TreeNode*> add;
        vector<int> tmpval;
        while(!temp.empty()){
            TreeNode* tmpnode = temp.front();
            temp.pop();
            tmpval.push_back(tmpnode -> val);
            if(tmpnode -> left)
                add.push(tmpnode -> left);
            if(tmpnode -> right)
                add.push(tmpnode -> right);
            //add.push();
        }
        if(!add.empty())
            que.push(add);
        if(!tmpval.empty())
        res.push_back(tmpval);
    }
    return res;

}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
