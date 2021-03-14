#include <iostream>
#include <string>
#include <stack>

using namespace std;

int calculate(string s) {
    int len = s.size();
    int ans = 0, sign = 1;
    stack<int> ops;
    ops.push(1);

    for (int i = 0; i < len; i++){
        if(s[i]== ' ') continue;
        if(s[i]== '+') sign = ops.top();
        if(s[i]== '-') sign = -ops.top();
        if(s[i] == '(') ops.push(sign);
        if(s[i] == ')') ops.pop();
        if(s[i] >= '0' && s[i] <= '9'){
            int tmp = 0;
            while (true){
                if(s[i] >= '0' && s[i] <= '9'){
                    tmp = tmp*10 + (s[i] - '0');
                    i++;
                }
                else{
                    i --;
                    ans += sign * tmp;
                    break;
                }
            }
        }
    }
    return ans;
}



int main() {
    int a = calculate("(1+(4+5+2)-3)+(6+8)");
    cout<<a;
    return 0;
}
