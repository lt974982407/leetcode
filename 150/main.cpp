#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int geNum(string str){
    bool flag = false;
    int res = 0;
    int i = 0;
    if(str[0] == '-'){
        flag = true;
        i++;
    } else if(str[0] == '+')
        i++;
    for(;i < str.size();i++){
        res = res * 10 + (str[i] - '0');
    }
    if(flag)
        res = - res;
    return res;
}

int evalRPN(vector<string>& tokens) {
    stack<int> s;
    for(int i = 0; i < tokens.size();i++){
        int num1,num2;
        if(tokens[i] == "+"){
            num1 = s.top();
            s.pop();
            num2 = s.top();
            s.pop();
            s.push(num1 + num2);
        } else if(tokens[i] == "-"){
            num1 = s.top();
            s.pop();
            num2 = s.top();
            s.pop();
            s.push(num2 - num1);
        }
        else if(tokens[i] == "*"){
            num1 = s.top();
            s.pop();
            num2 = s.top();
            s.pop();
            s.push(num2 * num1);
        }
        else if(tokens[i] == "/"){
            num1 = s.top();
            s.pop();
            num2 = s.top();
            s.pop();
            s.push(num2 / num1);
        }
        else{
            int tmp = geNum(tokens[i]);
            s.push(tmp);
        }
    }
    return s.top();
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
