#include <iostream>
#include <vector>

using namespace std;

void dfs (vector<int>candidates, int target, vector<vector<int>>& res,vector<int> tmp,int sum,int index){
    for(int i = index; i < candidates.size(); i++){
        if(sum + candidates[i] == target){
            tmp.push_back(candidates[i]);
            res.push_back(tmp);
            tmp.pop_back();
            continue;
        }
        else if(sum + candidates[i] > target)
            continue;
        else{
            tmp.push_back(candidates[i]);
            dfs(candidates,target,res,tmp,sum + candidates[i],i);
            tmp.pop_back();
        }

    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> tmp;
    dfs(candidates,target,res,tmp,0,0);
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
