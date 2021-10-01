#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& res,int target,int cnt,int index, vector<int> tmp){
    if(target == 0 && tmp.size() == cnt){
        res.push_back(tmp);
        return;
    }
    if(target <= 0 || tmp.size() >= cnt)
        return ;
    for(int i = index ; i <= 9; i++){
        tmp.push_back(i);
        dfs(res,target - i,cnt,i + 1,tmp);
        tmp.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    dfs(res, n,k,1,{});
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
