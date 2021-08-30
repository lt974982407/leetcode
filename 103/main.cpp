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

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    deque<TreeNode*> que;
    bool flag = true;
    que.push_back(root);
    while(!que.empty()){
        int size = que.size();
        vector<int> tmp;
        if(flag){
            for(int i = 0; i < size;i++){
                TreeNode* p = que.front();
                que.pop_front();
                if(p) {
                    tmp.push_back(p->val);
                    que.push_back(p -> left);
                    que.push_back(p -> right);
                }
                flag = false;
            }
        } else {
            for(int i = 0; i < size;i++){
                TreeNode* p = que.front();
                que.pop_front();
                if(p) {
                    tmp.insert(tmp.begin(),p->val);
                    que.push_back(p -> left);
                    que.push_back(p -> right);
                }
            }
            flag = true;
        }
        if(tmp.size())
            res.push_back(tmp);
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
