#include <iostream>
#include <vector>

using namespace std;

void rec(vector<vector<int>>& res,int n,int k ,int index,vector<int> tmp,int cnt){
    if(index == k){
        res.push_back(tmp);
        return;
    }
    for(int i = cnt; i <= n; i++){
        tmp.push_back(i);
        rec(res,n,k,index + 1,tmp,i+ 1);
        tmp.pop_back();
    }

}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    rec(res,n,k,0,{},0);
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
