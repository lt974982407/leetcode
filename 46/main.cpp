#include <iostream>
#include <vector>

using  namespace std;

void recursion (vector<vector<int>>& res,vector<int> nums ,vector<int> tmp,vector<int> visited,int index);
vector<vector<int>> permute(vector<int>& nums) {
    if (nums.size() == 0)
        return vector<vector<int>> (0);
    vector<int> tmp;
    vector<int> visited (nums.size(),0);
    vector<vector<int>> res;
    recursion(res,nums,tmp,visited,0);
    for (int i = 0; i < res.size(); i++){
        for (int j= 0; j < res[0].size(); j ++){
            cout<<res[i][j]<<' ';
        }
        cout<<endl;
    }
}

void recursion (vector<vector<int>>& res,vector<int> nums ,vector<int> tmp,vector<int> visited,int index){
    if (index == nums.size()){
        res.push_back(tmp);
    }
    else{
        for (int i = 0; i < nums.size(); i++){
            if(visited[i])
                continue;
            tmp.push_back(nums[i]);
            visited[i] = 1;
            recursion(res,nums,tmp,visited,index + 1);
            visited[i] = 0;
            tmp.pop_back();
        }
    }
}

void recursion1 (vector<vector<int>>& res,vector<int> nums ,vector<int> tmp,vector<int> visited,int index){
    if (index == nums.size()){
        res.push_back(tmp);
    }
    else{
        for (int i = 0; i < nums.size(); i++){
            if(visited[i])
                continue;
            if (i > 0 && nums[i] == nums[i - 1] && visited[i] ==0 )
                continue;
            tmp.push_back(nums[i]);
            visited[i] = 1;
            recursion(res,nums,tmp,visited,index + 1);
            visited[i] = 0;
            tmp.pop_back();
        }
    }
}
int main() {
    vector<int> test = {1,2,3,4};
    permute(test);
    return 0;
}
