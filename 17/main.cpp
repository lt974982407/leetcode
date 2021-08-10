#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<char,string> conn = {
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
};

//void dfs(string digits,int index, vector<bool> visited, vector<string>& res, string tmp){
//    if(index == digits.size()){
//        res.push_back(tmp);
//        return;
//    }
//    for(int i = 0; i< digits.size(); i++){
//        if(!visited[i] ){
//            if(i > 0 && !visited[i - 1] && digits[i] == digits[i - 1] )
//                continue;
//            for(char t : conn[digits[i]]){
//                tmp += t;
//                visited[i] = true;
//                dfs(digits,index + 1,visited,res,tmp);
//                tmp.pop_back();
//            }
//            visited [i] = false;
//        }
//    }
//}
//
//vector<string> letterCombinations(string digits) {
//    vector<bool> visited(digits.size(), false);
//    vector<string> res;
//    string tmp ="";
//    sort(digits.begin(),digits.end());
//    dfs(digits,0,visited,res,tmp);
//    for(string s : res)
//        cout<<s<<endl;
//    return res;
//}

void rec(string digits, int index, string tmp, vector<string> &res){
    if(index == digits.size()){
        res.push_back(tmp);
        return;
    }
    for(char s : conn[digits[index]]){
        tmp += s;
        rec(digits,index + 1, tmp,res);
        tmp.pop_back();
    }
}

vector<string> letterCombinations(string digits){
    vector<string> res;
    if(digits.size() == 0)
        return res;
    string  tmp = "";
    rec(digits,0,tmp,res);
    return res;
}

int main() {
    letterCombinations("23");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
