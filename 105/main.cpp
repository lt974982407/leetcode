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

TreeNode* rec(vector<int> preorder, vector<int>inorder, int start1,int len,int start2){
    cout<<start1<<' '<<len<<' '<<start2<<endl;
    if(len == 0)
        return nullptr;
    if(len == 1)
        return new TreeNode (preorder[start1]);
    int i ;
    for( i = 0; i < len; i++){
        if(preorder[start1] == inorder[i + start2])
            break;
    }
    TreeNode* p = new TreeNode (preorder[start1]);
    p -> left = rec(preorder,inorder,start1 + 1,i, start2);
    p -> right = rec(preorder,inorder,i  + start1 + 1,len - i  - 1,start2 + i + 1);
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return rec(preorder,inorder,0,preorder.size(),0);
}

int main() {
    vector<int> test1 = {3,9,20,15,7};
    vector<int> test2 = {9,3,15,20,7};
    buildTree(test1,test2);
    return 0;
}
