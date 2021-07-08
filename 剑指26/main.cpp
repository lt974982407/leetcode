#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


bool isSubStructure1(TreeNode* A, TreeNode* B) {
    if(B == NULL)
        return true;
    if(A == NULL)
        return false;
    if(A ->val == B ->val)
        return (isSubStructure1(A->left,B->left)&& isSubStructure1(A->right,B->right)) ;
    else
        return false;

}

bool isSubStructure(TreeNode* A, TreeNode* B){
    if(A== NULL || B == NULL)
        return false;
    else
        return isSubStructure1(A,B) || isSubStructure(A->left,B)|| isSubStructure(A->right,B);
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
