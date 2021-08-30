#include <iostream>

using namespace std;

int numDecodings(string s) {
    int res = 1, pre = 0;
    for(int i = 0; i < s.size(); i++){
        int tmp = 0;
        if(s[i] != '0')
            tmp = res + tmp;
        if( i > 0 &&  s[i -1] - '0' != 0 && ((s[i] - '0')  + (s[i -1] - '0') * 10 <= 26))
            tmp = tmp + pre;
        pre = res;
        res = tmp;
        cout<<pre <<' '<<res<<endl;
    }
    return res;
}

int main() {
    cout<<numDecodings("12");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
