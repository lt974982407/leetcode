#include <iostream>
#include <stack>

using namespace std;

string simplifyPath(string path) {
    stack<string> s;
    string tmp;
    path = path + "/";
    for(int i = 0; i < path.size();i++){
        if(path[i] == '/') {
            if (!tmp.empty()) {
                //cout<<tmp<<endl;
                if(tmp == ".."){
                    if(!s.empty())
                        s.pop();
                }
                else if(tmp != ".")
                    s.push(tmp);
                tmp.clear();
            }
        }
        else{
            tmp = tmp + path[i];
        }
    }
    string res = "";
    while(!s.empty()){
        //cout<<s.top()<<endl;
        if(s.top() != ".")
            res = "/" + s.top() + res;
        s.pop();
    }
    if(res.size() == 0)
        res = "/";
    return res;
}

int main() {
    cout<<simplifyPath("/a//b////c/d//././/..")<<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
