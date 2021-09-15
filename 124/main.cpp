#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//回溯法，超时

unordered_map<TreeNode*, TreeNode*> parent;
unordered_map<TreeNode*, int> visited;

void getparent(TreeNode* p){
    if(p -> left) {
        parent[p->left] = p;
        getparent(p -> left);
    }
    if(p -> right){
        parent[p -> right] = p;
        getparent(p -> right);
    }
}

void rec(int& res, int cnt,TreeNode* p){
    cnt = cnt + p -> val;
    res = max(cnt,res);
    if(p -> left && !visited[p -> left] == 1){
        visited[p -> left] == 1;
        rec(res,cnt,p -> left);
        visited[p -> left] = 0;
    }
    if(p -> right && !visited[p -> right] == 1){
        visited[p -> right] == 1;
        rec(res,cnt,p -> right);
        visited[p -> right] = 0;
    }
    if(parent[p] && visited[parent[p]] == 1){
        visited[parent[p] ] = 1;
        rec(res,cnt,parent[p]);
        visited[parent[p]] = 0;
    }
}

int maxPathSum1(TreeNode* root) {
    getparent(root);
    parent[root] = nullptr;
    queue<TreeNode*> que;
    que.push(root);
    int res = INT_MIN;
    while(!que.empty()){
        int tmp = INT_MIN;
        TreeNode* p = que.front();
        que.pop();
        if(p -> left)
            que.push(p -> left);
        if(p -> right)
            que.push(p -> right);
        rec(tmp,0,p);
        visited.clear();
        res = max(tmp,res);
    }
    return res;
}

//递归

int rec1(TreeNode* p,int& res){
    if(!p)
        return 0;
    int leftsum = max(rec1(p -> left,res),0);
    int rightsum = max(rec1(p -> right,res),0);
    res = max(res,leftsum + p -> val + rightsum);
    //cout<<res<<' '<<p -> val<<endl;
    return  p -> val + max(leftsum ,rightsum);
}

int maxPathSum(TreeNode* root) {
    int res = INT_MIN;
    rec1(root,res);
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
