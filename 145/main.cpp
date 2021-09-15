#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> s;
    TreeNode* pre = nullptr;
    while(root || !s.empty()){
        while(root){
            s.push(root);
            root = root -> left;
        }
        TreeNode* tmp = s.top();
        s.pop();
        if(!tmp -> right || tmp -> right == pre){
            res.push_back(tmp -> val);
            pre = root;
            root = nullptr;
        } else{
            s.push(root);
            root = root -> right;
        }

    }
    return  res;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
