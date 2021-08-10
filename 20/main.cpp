#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s) {
    stack<char> tmp;
    for(char c : s){
        if(c == '(' || c == '[' || c == '{')
            tmp.push(c);
        else if(c == ')'){
            if(!tmp.empty()&&tmp.top() == '(')
                tmp.pop();
            else
                return false;
        }
        else if(!tmp.empty()&&c == '}'){
            if(tmp.top() == '{')
                tmp.pop();
            else
                return false;
        }
        else if(c == ']'){
            if(!tmp.empty()&&tmp.top() == '[')
                tmp.pop();
            else
                return false;
        }
    }
    return tmp.empty();
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
