#include <iostream>
#include <stack>

using namespace std;

int calculate(string s) {
    stack<int> s1,s2;
    int res = 0;
    s2.push(1);
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' ')
            continue;
        else if(s[i] == '+')
            s2.push(1);
        else if(s[i] == '-')
            s2.push(-1);
        else if(s[i] == '*')
            s2.push(3);
        else if(s[i] == '/')
            s2.push(4);
        else if(s[i] >= '0' && s[i] <= '9'){
            int num = 0;
            while(i < s.size() && s[i] >= '0' && s[i] <= '9'){
                num = num * 10 + (s[i] - '0');
                i++;
            }
            i--;
            //cout<<num<<endl;
            if(s2.top() == 3){
                num = num * s1.top();
                s1.pop();
                s2.pop();
            } else if(s2.top() == 4){
                //cout<<num<<endl;
                num = s1.top() / num;
                //cout<<num<<endl;
                s1.pop();
                s2.pop();
            }
            s1.push(num);

        }
    }
    while(!s1.empty()){
        res = res + s1.top() * s2.top();
        //cout<<s1.top()<<endl;
        s1.pop();
        s2.pop();
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
