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

int main() {
    cout<<replaceSpace("   ");
    return 0;
}
