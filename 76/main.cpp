#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<char,int>m1,m2;

bool check(){
    for (unordered_map<char, int>::iterator it = m2.begin(); it != m2.end(); ++it){
        if(m1[it->first] < it -> second)
            return false;
    }
    return true;
}

string minWindow(string s, string t) {
    //unordered_map<char,int> m1,m2;
    for(char c : t)
        m2[c] ++;
    int minlen = max(s.size() + 1,t.size() + 1);
    int res = 0,l = 0, r = -1;
    while(r <  int(s.size()) ){
        if(r - l + 1 < int(t.size()) ||!check()){
            r++;
            m1[s[r]]++;
        }else{
            if(minlen > (r - l + 1)){
                res = l;
                minlen = r - l + 1;
            }
            m1[s[l]]--;
            l++;
            cout<<r - l + 1 <<endl;
        }
    }
    if(minlen == max(s.size() + 1,t.size() + 1))
        return "";
    else
        return s.substr(res,minlen);
}

int main() {
    cout<<minWindow("ADOBECODEBANC","ABC");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
