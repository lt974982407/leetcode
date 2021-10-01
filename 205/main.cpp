#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool isIsomorphic(string s, string t) {
    unordered_map<char,char> m;
    unordered_set<char> se;
    if(s.size() != t.size())
        return false;
    for(int i = 0; i < s.size();i++){
        if(m.find(s[i]) == m.end()&& se.find(t[i]) == se.end() ){
            m[s[i]] = t[i];
            se.insert(s[i]);
        }
        else if(m[s[i]] != t[i])
            return false;
    }
    return true;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
