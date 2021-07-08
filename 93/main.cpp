#include <iostream>
#include <vector>

using namespace std;

void dfs (string s,int index,int num, vector<string>& res,string tmp){
    if (index == 5 && num == s.size()){
        res.push_back(tmp);
        return;
    }
    if (num == s.size() || index == 5 && num < s.size()){
        return;
    }
    int sum = 0;
    if(index != 1)
        tmp += ".";
    if (s[num] == '0'){
        tmp += '0';
        dfs(s,index + 1, num + 1,res,tmp);
    } else{
        for(int i = 0; (i < 3) && (num + i < s.size()); i++){
            sum = sum * 10 + (s[num + i] - '0');
            //cout<<sum<<endl;
            if (sum <= 255 && sum >= 0){
                tmp = tmp + s[num + i];
                dfs(s,index + 1, num + i + 1,res,tmp);
            }
            else
                continue;
        }
    }

}

vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    string tmp = "";
    dfs(s,1,0,res,tmp);
    for (int i = 0 ; i < res.size();i++){
        cout<<res[i]<<endl;
    }
    return res;
}

int main() {
    restoreIpAddresses("25525511135");
    return 0;
}
