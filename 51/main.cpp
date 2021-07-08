#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<int> s1;
unordered_set<int> s2;
unordered_set<int> s3;

void dfs(vector<vector<int>>&res,vector<int> tmp,int n ,int index){
    if(index == n){
        res.push_back(tmp);
    }
    for(int i = 0; i < n ; i++){
        if(s1.find(i)== s1.end()&&s2.find(i + index)==s2.end()&&s3.find(i - index)== s3.end()){
            s1.insert(i);
            s2.insert(i + index);
            s3.insert(i - index);
            tmp.push_back(i);
            dfs(res,tmp,n,index + 1);
            tmp.pop_back();
            s1.erase(i);
            s2.erase(i + index);
            s3.erase(i - index);
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<int>> res;
    vector<int> tmp;
    dfs(res,tmp,n,0);
    if(res.size()==0)
        return vector<vector<string>>(0);
    vector<vector<string>> ans;
    for(int i = 0; i < res.size(); i++){
        vector<string> tmp;
        for(int j = 0; j< n; j++){
            string s(n,'.');
            s[res[i][j]] = 'Q';
            tmp.push_back(s);
        }
        ans.push_back(tmp);
    }
    return ans;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
