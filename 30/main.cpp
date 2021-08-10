#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> res;
    unordered_map<string,int> wmap;
    if(words.size() == 0)
        return res;
    for(string word : words)
        wmap[word] += 1;
    unordered_map<string,int> smap;
    for(int i = 0; i < words[0].size(); i++){
        for(int t = 0; t < words.size() - 1; t ++)
            smap[s.substr(i + words[0].size()*t,words[0].size())] += 1;
        for(int k = 0; i + k + words.size()*words[0].size() <= s.size(); k += words[0].size()){
            cout<<i + k + words.size()*words[0].size()<<endl;
            smap[s.substr(i + k +words[0].size()*(words.size() - 1),words[0].size())] += 1;
            cout<<s.substr(i + k +words[0].size()*(words.size() - 1),words[0].size())<<endl;
            cout<<i + k +words[0].size()*(words.size() - 1)<<endl;
            bool flag = true;
            for(int m = 0; m < words.size(); m++){
                cout<<smap[words[m]]<<words[m]<<endl;
                if(smap[words[m]] != wmap[words[m]])
                    flag = false;
            }
            if(flag)
                res.push_back(i + k);
            smap[s.substr(i + k ,words[0].size())] -= 1;
        }
        smap.clear();
    }
    for(int i : res)
        cout<<i<<endl;
    return res;
}

int main() {
    vector<string> test = {"word","good","best","good"};
    findSubstring("wordgoodgoodgoodbestword",test);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
