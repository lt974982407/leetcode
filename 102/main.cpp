#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void rec(vector<vector<int>> & res,deque<TreeNode*> que){
    vector<int> tmp;
    TreeNode* p;
    while(!que.empty()){
        p = que.front();
        que.pop_front();
        if(p){
            tmp.push_back(p -> val);

        }
    }
}


vector<vector<int>> levelOrder(TreeNode* root) {
    TreeNode* p;
    deque<TreeNode*> que;
    vector<vector<int>>  res;
    que.push_back(root);
    while(!que.empty()){
        vector<int> tmp;
        int size = que.size();
        for (int i = 0; i < size; i++) {
            p = que.front();
            que.pop_front();
            if (p) {
                tmp.push_back(p->val);
                que.push_back(p -> left);
                que.push_back(p -> right);
            }
        }
        if(tmp.size() > 0)
            res.push_back(tmp);
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
