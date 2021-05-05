#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

map <int,int> index;

TreeNode* recur(vector<int>& preorder, vector<int>& inorder, int pre_left, int pre_right,int in_left,int in_right){
    if (pre_left > pre_right)
        return nullptr;

    int in_root = index[preorder[pre_left]];
    TreeNode* root = new TreeNode(preorder[pre_left]);
    int left_size = in_root - in_left;

    root -> left = recur(preorder,inorder,pre_left + 1, pre_left + left_size, in_left, in_root - 1);
    root -> right = recur(preorder,inorder,pre_left + left_size + 1,pre_right,in_root + 1, in_right);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int len = preorder.size();
    for (int i = 0;i < len;i++){
        index[inorder[i]] = i;
    }
    return recur(preorder,inorder,0,len -1,0,len -1);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
