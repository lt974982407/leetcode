#include <iostream>

using namespace std;

void rec(string s,int index,int& res){
    if(index == s.size() - 1){
        res++;
        return;
    }
    else if(index == s.size() - 2){
        int num = (s[index] - '0') * 10 + (s[index + 1] - '0');
        if(num <= 25&& s[index] != '0'){
            res ++;
        }
        rec(s,index+1,res);
        return;
    }
    rec(s,index + 1, res);
    if((s[index] - '0') * 10 + (s[index + 1] - '0') <= 25 && s[index] != '0')
        rec(s,index + 2,res);
}

int translateNum(int num) {
    int res = 0;
    string s = to_string(num);
    rec(s,0,res);
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
