#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs (vector<string>& res, vector<int>& visited, string tmp, int index, string s){
    if (index == s.size()){
        res.push_back(tmp);
        return;
    }
    for(int i = 0; i < s.size(); i++){
        if(visited[i] == 1)
            continue;
        if(i > 0 && visited[i - 1] && !visited[i] && s[i] == s[i - 1])
            continue;
        visited[i] = 1;
        tmp = tmp + s[i];
        dfs(res,visited,tmp,index + 1,s);
        tmp.pop_back();
        visited[i] = 0;
    }
}

vector<string> permutation(string s) {
    if(s.size() == 0)
        return vector<string>(0);
    sort(s.begin(),s.end());
    vector<int> visited(s.size(),0);
    vector<string> res;
    string tmp = "";
    dfs(res,visited,tmp,0,s);
    return res;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
