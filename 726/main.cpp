#include <iostream>
#include <string>
#include <map>
#include <stack>

using namespace std;

string countOfAtoms(string formula) {
    stack<map<string,int>> s;
    s.push({});
    for(int i = 0; i< formula.size(); i++){
        if (formula[i] >= 'A' && formula[i] <= 'Z'){
            int tmp = 1;
            while (formula[i + tmp] >= 'a' && formula[ i + tmp] <= 'z'){
                tmp ++;
            }
            int temp = 0;
            if (formula[i + tmp] >= '0' && formula[i + tmp] <= '9'){
                int num = 0;
                while(formula[i + tmp + temp] >= '0' && formula[i + tmp + temp] <= '9'){
                    num = num * 10 + (formula[i + tmp + temp] - '0');
                    temp ++;
                }
                if(s.top().find(formula.substr(i,tmp))==s.top().end())
                    s.top()[formula.substr(i,tmp)] = num;
                else
                    s.top()[formula.substr(i,tmp)] += num;
            } else{
                if(s.top().find(formula.substr(i,tmp))==s.top().end())
                    s.top()[formula.substr(i,tmp)] = 1;
                else
                    s.top()[formula.substr(i,tmp)] += 1;
            }
            i = i + tmp - 1 + temp;
        }
        else if(formula[i] == '('){
            s.push({});
        } else if (formula[i] == ')'){
            map<string , int> tmp = s.top();
            s.pop();
            int stmp = 1;
            if (formula[i + stmp] >= '0' && formula[i + stmp] <= '9'){
                int num = 0;
                while(formula[i + stmp] >= '0' && formula[i + stmp ] <= '9'){
                    num = num * 10 + (formula[i + stmp] - '0');
                    stmp ++;
                }
                for (map<string, int>::iterator it = tmp.begin(); it != tmp.end(); ++it){
                    it -> second = it -> second * num;
                }
                i = i + stmp - 1;
            }
            for (map<string, int>::iterator it = tmp.begin(); it != tmp.end(); ++it){
                if(s.top().find(it->first) != s.top().end()){
                    s.top()[it->first] = s.top()[it->first] + it->second;
                } else{
                    s.top()[it->first] = it -> second;
                }
            }
        }

    }
    string ans = "";
    for (map<string, int>::iterator i = s.top().begin(); i != s.top().end(); ++i){
        ans += i ->first;
        //ans += ":";
        if(i -> second != 1)
            ans += to_string(i->second);
    }
    return ans;

}

int main() {
    std::cout << countOfAtoms("B7H11He49Li20N46O35") << std::endl;
    return 0;
}
