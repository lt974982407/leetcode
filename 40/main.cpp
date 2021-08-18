#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>>  res;

void dfs(vector<int> candidates,vector<int> tmp,  int target,int sum,int index){
    for(int i = index; i < candidates.size(); i++){
        if(i > index && candidates[i] == candidates[ i -1])
            continue;
        tmp.push_back(candidates[i]);
        if(sum + candidates[i] == target){
            cout<<sum + candidates[i]<<endl;
            res.push_back(tmp);
            tmp.pop_back();
            return ;
        }else if(sum + candidates[i] > target)
            return;
        dfs(candidates,tmp,target,sum + candidates[i],i + 1);
        tmp.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    //vector<bool> visited(candidates.size(),false);
    //vector<vector<int>> res;
    vector<int> tmp;
    dfs(candidates,tmp,target,0,0);
//    for(int i = 0; i < res.size(); i++){
//        for(int k= 0 ; k < res[i].size(); k++){
//            cout<<res[i][k]<<' ';
//        }
//        cout<<endl;
//    }
    return res;
}

int main() {
    vector<int> test = {14,6,25,9,30,20,33,34,28,30,16,12,31,9,9,12,34,16,25,32,8,7,30,12,33,20,21,29,24,17,27,34,11,17,30,6,32,21,27,17,16,8,24,12,12,28,11,33,10,32,22,13,34,18,12};
    combinationSum2(test,27);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
