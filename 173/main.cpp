#include <iostream>
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

class BSTIterator {
private:
    TreeNode* cur;
    stack<TreeNode*> s;
public:
    BSTIterator(TreeNode* root) {
       cur = root;
    }

    int next() {
        while(cur){
            s.push(cur);
            cur = cur -> left;
        }
        TreeNode* tmp = s.top();
        s.pop();
        cur = cur -> right;
        return tmp -> val;
    }

    bool hasNext() {
        return cur || !s.empty();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
