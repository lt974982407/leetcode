#include <iostream>
#include <vector>

using namespace std;

void rec(vector<vector<int>>& res,int k ,vector<int> tmp,int cnt,vector<int> nums){
    if(tmp.size() == k ){
        res.push_back(tmp);
        return;
    }
    for(int i = cnt; i < nums.size(); i++){
        tmp.push_back(i);
        rec(res,k,tmp,i+ 1,nums);
        tmp.pop_back();
    }

}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    res.push_back({});
    for(int i = 1; i <= nums.size(); i++){
        rec(res,i,{},0,nums);
    }
    return res;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
