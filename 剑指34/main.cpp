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

void dfs(vector<vector<int>>& res,TreeNode* node,int target,int num,vector<int> tmp){
    if(!node)
        return;
    if(num + node -> val == target && !node -> left && !node-> right){
        tmp.push_back(node->val);
        res.push_back(tmp);
        return;
    }
    //else if (num + node -> val > target)
    //return;
    tmp.push_back(node -> val);
    dfs(res,node->left,target,num + node -> val,tmp);
    //tmp.pop_back();
    dfs(res,node->right,target,num + node -> val,tmp);
}

vector<vector<int>> pathSum(TreeNode* root, int target) {
    if(!root)
        return vector<vector<int>>(0);
    vector<vector<int>> res;
    vector<int> tmp;
    dfs(res,root,target,0,tmp);
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
