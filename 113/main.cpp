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

void rec(vector<vector<int>>& res, int sum,TreeNode* root,vector<int> tmp){
    if (!root)
        return;
    tmp.push_back(root -> val);
    if(sum - root -> val == 0 && !root -> left && !root -> right){
        res.push_back(tmp);
    }
    rec(res,sum - root -> val,root -> left,tmp);
    rec(res,sum - root -> val,root -> right,tmp);
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> res;
    rec(res,targetSum,root,{});
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
