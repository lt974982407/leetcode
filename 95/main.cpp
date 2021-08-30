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

vector<TreeNode*> rec(int start, int end){
    if(start > end)
        return {NULL};
    vector<TreeNode*> res;
    for(int i = start; i <= end; i ++){
        vector<TreeNode*> left = rec(start, i - 1);
        vector<TreeNode*> right = rec(i + 1, end);
        for(int m = 0 ; m < left.size(); m++){
            for(int n = 0; n < right.size(); n++){
                TreeNode* cur = new TreeNode (i);
                cur -> left = left[m];
                cur -> right = right[n];
                res.push_back(cur);
            }
        }
    }
    return res;
}


vector<TreeNode*> generateTrees(int n) {
    return rec(1,n);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
