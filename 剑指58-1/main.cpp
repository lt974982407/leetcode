#include <iostream>
#include <vector>

using namespace std;

string reverseWords(string s) {
    vector<string> tol;
    string tmp,res;
    int i = 0;
    while(i < s.size()&& s[i] ==' ')
        i++;
    for (;i < s.size();i++){
        if(s[i] == ' ' && tmp != ""){
            tol.push_back(tmp);
            tmp.clear();
        } else if(s[i] != ' '){
            tmp += s[i];
        }
    }
    if(tmp != "")
        tol.push_back(tmp);
    for(int k = tol.size() - 1; k >= 0; k--){
        res = res + tol[k];
        res += ' ';
    }
    res.pop_back();
    return res;
}

int main() {
    std::cout <<reverseWords("  hello world!  ")<< std::endl;
    return 0;
}
