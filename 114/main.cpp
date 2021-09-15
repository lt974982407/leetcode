#include <iostream>


using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void rec(TreeNode* & pre, TreeNode* & cur){
    if(!cur)
        return;
    TreeNode* tmp = cur -> right;
    if(pre){
        pre -> right = cur;
    }
    if(pre)
        cout<<"pre"<<pre->val<<' ';
    if(cur)
        cout<<"cur"<<cur->val<<' ';
    cout<<endl;
    pre = cur;
    cur = cur -> left;
    rec(pre,cur);
    cur = tmp;
    rec(pre,cur);
}


void flatten(TreeNode* root) {
    TreeNode* p = nullptr;
    rec(p,root);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
