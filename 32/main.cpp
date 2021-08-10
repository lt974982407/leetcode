#include <iostream>
#include <stack>

using namespace std;

int longestValidParentheses(string s) {
    stack<int> p;
    int num = 0;
    int res = 0;
    int tmp = 0;
    int count = 0;
    for(int i = 0; i < s.size(); i++){
        if(num == 0 && s[i] == ')'){
            p.push(-1);
        }
        else if(s[i] == '('){
            num ++;
            p.push(0);
        }
        else if(s[i] == ')'){
            num --;
            if(p.top() != 0){
                int tmp = 0;
                while(p.top() != 0){
                    tmp += p.top();
                    p.pop();
                }
                p.pop();
                p.push(tmp + 2);
            } else
                p.top() = 2;
        }
    }
    while(!p.empty()){
        if(p.top() >= 2 ){
            tmp += p.top();
            res = max(res,tmp);
        }
        else {
            tmp = 0;
        }
        p.pop();
    }
    return res;
}

int main() {
    cout<<longestValidParentheses(")()(((())))(")<<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
