#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
string shortestPalindrome(string s) {
    int end = s.size();
    while(end > 0){
        int i = 0, j = end - 1;
        while (i < j){
            if(s[i] != s[j])
                break;
            i ++;
            j --;
        }
        if(i >= j)
            break;
        end--;
    }
    string res = s;
    for(int i = end + 1; i < s.size(); i++){
        res = s[i] + res;
    }
    return res;
}*/

string shortestPalindrome(string s) {
    string rev = s;
    reverse(rev.begin(),rev.end());
    string tmp = s + '#' + rev;
    vector<int> next;
    next.push_back(0);
    int x = 1, now = 0, pre = 0;
    //cout<<tmp.size()<<endl;
    while(x < tmp.size()){
        //cout<<x<<' '<<now<<endl;
        if(tmp[now] == tmp[x]){
            now ++;
            x++;
            next.push_back(now);
        }else if(now > 0)
            now = next[now - 1];
        else{
            x++;
            next.push_back(0);
        }
    }
    string rev2 = s.substr(next[tmp.size() - 1]);
    reverse(rev2.begin(),rev2.end());
    return rev2 + s;
}

int main() {
    cout<<shortestPalindrome("abeebac")<<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
