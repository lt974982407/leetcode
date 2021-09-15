#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<string> s1;
unordered_set<int> s2;

void rec(vector<string>& res,string s,int index,vector<string> tmp){
    if(index == s.size()){
        string st = "";
        for(string i : tmp)
            st = st + i + " ";
        st.pop_back();
        res.push_back(st);
        return ;
    }
    for(unordered_set<int> ::iterator it = s2.begin();it != s2.end(); it++){
        if(index + *it - 1< s.size() && s1.find(s.substr(index,*it))!= s1.end()){
            tmp.push_back(s.substr(index,*it));
            rec(res,s,index + *it,tmp);
            tmp.pop_back();
        }
    }

}


vector<string> wordBreak(string s, vector<string>& wordDict) {
    for(string index : wordDict){
        s1.insert(index);
        s2.insert(index.size());
    }
    vector<string> res;
    rec(res,s,0,{});
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
