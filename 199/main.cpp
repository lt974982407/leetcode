#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    queue<TreeNode*> que;
    if(!root)
        return res;
    que.push(root);
    while(!que.empty()){
        int size = que.size();
        for(int i = 0; i < size; i++){
            TreeNode* tmp = que.front();
            que.pop();
            if(tmp -> left)
                que.push(tmp -> left);
            if(tmp -> right)
                que.push(tmp -> right);
            if(i == size - 1)
                res.push_back(tmp -> val);
        }
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
