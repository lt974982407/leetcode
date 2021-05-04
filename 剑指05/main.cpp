#include <iostream>
#include <string>

using namespace std;

string replaceSpace(string s) {
    for (int i = 0; i < s.size(); i++){
        if (s[i]==' '){
            s = s.substr(0,i) + "%20"+s.substr(i+1);
            i = i + 2;
        }
    }
    return s;
}

string replaceSpace1(string s) {
    int len = s.length();
    if(len == 0) return s;

    int num = 0;

    for(int i = 0; i < len; i++) {
        if (s[i] == ' ')
        num++;
    }

    if (num == 0)
        return s;
    int newlen = len + 2 * num;
    s.resize(newlen);

    while(newlen > len ){
        if(s[len] == ' '){
            s[newlen--] = '0';
            s[newlen--] = '2';
            s[newlen--] = '%';
            len--;
        }
        else{
            s[newlen--] = s[len--];
        }
    }
    return s;
}

int main() {
    cout<<replaceSpace("   ");
    return 0;
}
