#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s;
    int res = 1;
    for(int num : nums){
        s.insert(num);
    }
    for(int num : s){
        if(s.find(num - 1) == s.end()){
            int tmp = num + 1;
            int curlen = 1;
            while(s.find(tmp) != s.end()){
                tmp ++;
                curlen ++;
            }
            res= max(res,curlen);
        }
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
