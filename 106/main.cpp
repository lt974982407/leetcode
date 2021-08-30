#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

unordered_map<int,int> index;

TreeNode* rec(vector<int> inorder, vector<int>postorder, int start1,int len,int start2){
    cout<<start1<<' '<<len<<' '<<start2<<endl;
    if(len == 0)
        return nullptr;
    if(len == 1)
        return new TreeNode (postorder[start2 + len - 1]);
    TreeNode* p = new TreeNode (postorder[start2 + len - 1]);
    int mid = index[postorder[start2 + len - 1]];
    p -> left = rec(inorder,postorder,start1 ,mid - start1 , start2);
    p -> right = rec(inorder,postorder,mid + 1,len - mid + start1  - 1,start2 + mid - start1);
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    for(int i = 0 ; i < postorder.size() ; i++){
        index[inorder[i]] = i;
    }
    return rec(inorder,postorder,0,postorder.size(),0);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
