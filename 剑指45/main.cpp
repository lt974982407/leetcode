#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b){
    return a + b < b + a;
}

string minNumber(vector<int>& nums) {
    vector<string> tmp;
    for(auto i : nums)
        tmp.push_back(to_string(i));
    sort(tmp.begin(),tmp.end(),compare);
    string res = "";
    for(auto i : tmp)
        res = res + i;
    return res;
}

int main() {
    vector<int> test = {3,30,34,5,9};
    std::cout << minNumber(test) << std::endl;
    return 0;
}
