#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void forder(TreeNode* root,string& tmp){
    if(!root){
        tmp = tmp + ",$";
        return;
    }
    tmp = tmp + "," + to_string(root -> val);
    forder(root -> left,tmp);
    forder(root -> right,tmp);
}

string serialize(TreeNode* root) {
    string res = "";
    forder(root,res);
    return res;
}

// Decodes your encoded data to tree.
void getTree(string data,int& index, TreeNode*& hhh){
    if(index >= data.size())
        return;
    bool flag = false;
    int i = index + 1;
    if(data[i] == '-'){
        i++;
        flag = true;
    }
    if (data[i] >= '0' && data[i] <= '9'){
        int num = 0;
        while(data[i] >= '0' && data[i] <= '9'){
            num = num*10 + (data[i] - '0');
            i++;
        }
        if(flag)
            num = num * -1;
        hhh = new TreeNode (num);
        index = i;
        cout<<index<<endl;
        getTree(data,index,hhh->left);
        getTree(data,index ,hhh->right);
    }
    else if (data[i] == '$'){
        //cout<<i<<endl;
        index = i + 1;
        return;
    }

}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if(data.length() == 0)
        return NULL;
    cout<<data<<endl;
    TreeNode * root = NULL;
    int index = 0;
    getTree(data,index,root);
    return root;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
