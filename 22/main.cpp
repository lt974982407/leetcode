#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void rec(int index,string tmp,vector<string>& res,stack<char> bracket){
    if(index == 0){
        res.push_back(tmp);
        return;
    }
    if(bracket.size() < index){
        bracket.push('(');
        tmp += '(';
        rec(index,tmp,res,bracket);
        tmp.pop_back();
        bracket.pop();
    }
    if(!bracket.empty()){
        tmp += ')';
        bracket.pop();
        rec(index - 1,tmp,res,bracket);
    }
}

vector<string> generateParenthesis(int n) {
    string tmp = "";
    vector<string> res;
    stack<char> bracket;
    rec(n,tmp,res,bracket);
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
