#include <iostream>
#include <vector>

using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    int cnt = 0;
    vector<int> tmp;
    vector<string> res;
    for(int i = 0; i < words.size(); i++){
        //cout<<cnt<<endl;
        if(cnt + words[i].size() <= maxWidth){
            tmp.push_back(i);
            cnt = cnt + words[i].size() + 1;
        }
        else{
            string ares = "";
            //cout<<cnt<<' ';
            if(tmp.size() == 1){
                ares = words[tmp[0]];
                while(ares.size() < maxWidth)
                    ares = ares + " ";
                res.push_back(ares);
                cnt = 0;
                tmp.clear();
            }
            else{
                int div = (maxWidth - cnt + tmp.size()) / (tmp.size()-1);
                int mod = (maxWidth - cnt + tmp.size()) % (tmp.size()-1);
                //cout<<div<<' '<<mod<<endl;
                for(int t = 0 ; t < tmp.size() - 1; t++){
                    ares = ares + words[tmp[t]];
                    for(int k = 0; k < div; k++)
                        ares = ares + " ";
                    if(mod > 0){
                        ares = ares + " ";
                        mod--;
                    }
                }
                ares = ares + words[tmp[tmp.size()-1]];
                tmp.clear();
                cnt = 0;
                res.push_back(ares);
                i--;
            }
        }
    }
    //cout<<tmp.size()<<endl;
    string ares = "";
    for(int i = 0; i < tmp.size();i++){
        ares = ares + words[tmp[i]] + " ";
    }
    if(ares.size() > maxWidth)
        ares.pop_back();
    else{
        while(ares.size() < maxWidth)
            ares = ares + " ";
    }
    //cout<<ares<<endl;
    res.push_back(ares);
    return res;
}

int main() {
    vector<string> test = {"What","must","be","acknowledgment","shall","be"};
    fullJustify(test,16);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
