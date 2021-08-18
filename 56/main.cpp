#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    if(intervals.size() == 0)
        return res;
    sort(intervals.begin(),intervals.end());
    int begin = intervals[0][0], end = intervals[0][1];
    for(int i = 1; i < intervals.size(); i++ ){
        if(intervals[i][0] > begin){
            res.push_back({begin,end});
            begin = intervals[i][0];
            end = intervals[i][1];
        }
        else
            end = max(end,intervals[i][1]);
    }
    res.push_back({begin,end});
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<vector<int>> test = {{1,2},{2,1},{3,4},{7,9},{1,21}};
    sort(test.begin(),test.end());
    for(vector<int> s : test)
        for(int i : s)
            cout<<i<<endl;
    return 0;
}
