#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* GetNext(TreeNode* p){
    TreeNode* next = nullptr;

    if(p -> right != nullptr){
        TreeNode* tmp = p -> right;
        while(tmp -> left != nullptr)
            tmp = tmp -> left;
        next = tmp;
    }
    else{
        TreeNode* curr = p;
        TreeNode* par = p -> parent;
        while(par != nullptr && curr == par -> right){
            curr = par;
            par = par -> parent;
        }
        next = par;
    }
    return next;

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
