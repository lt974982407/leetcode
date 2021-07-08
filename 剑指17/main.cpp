#include <iostream>
#include <vector>

using namespace std;

vector<string> res;

vector<int> printNumbers(int n) {
    int num = 1;
    for (int i = 0; i < n; i++){
        num *= 10;
    }
    vector<int> res;
    for (int i = 1; i < num; i++){
        res.push_back(i);
    }
    return res;
}

void permutation(int index,int len, string num){
    if (index == len){
        res.push_back(num);
        return;
    }
    else{
        for (int i = 0; i < 10; i++){
            if(i == 0 && num == "") {
                permutation(index + 1,len,num);
            }
            else{
                num = num + to_string(i);
                permutation(index + 1,len,num);
                num.pop_back();
            }
        }
    }
}

int main() {
    string num = "";
    permutation(0,3,num);
    for (int i = 0; i < res.size(); i++){
        cout <<res[i]<<' ';
    }
    return 0;
}
