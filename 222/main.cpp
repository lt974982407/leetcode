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

bool existed(TreeNode* root,int index,int height){
    int bit = 1 << (height - 1);
    while(bit){
        //cout<<( bit)<<endl;
        if(index & bit)
            root = root -> right;
        else
            root = root -> left;
        bit = bit >> 1;
    }
    return root != nullptr;
}


int countNodes(TreeNode* root) {
    if(!root)
        return 0;
    TreeNode* p = root;
    int height = -1;
    while(p){
        p = p -> left;
        height++;
    }
    int low = 0, high = (1 << height) - 1;
    //cout<<high<<endl;
    while(low < high){
        //cout<<low<<' '<<high<<endl;
        int mid = (low + high + 1) / 2;
        bool flag = existed(root,mid,height);
        if(flag)
            low = mid ;
        else
            high = mid - 1;
    }
    cout<<low<<endl;
    int res = (1 << height) - 1 + low + 1;
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
