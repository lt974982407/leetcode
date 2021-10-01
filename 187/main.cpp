#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
    vector<string> res;
    unordered_map<string,int> m;
    for(int i = 0; i <= s.size() - 10; i++){
        string tmp = s.substr(i,10);
        m[tmp]++;
        if(m[tmp] > 1)
            res.push_back(tmp);
    }
    return res;
}

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
