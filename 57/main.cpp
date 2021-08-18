#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> res;
    bool fin = false;
    int begin = newInterval[0],end = newInterval[1];
    for(int i = 0; i < intervals.size(); i++){
        if(intervals[i][0] > newInterval[1]) {
            if (!fin) {
                fin = true;
                res.push_back({begin,end});
            }
            res.push_back(intervals[i]);
        }
        else if(intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i]);
        }
        else{
            begin = min(begin,intervals[i][0]);
            end = max(end,intervals[i][1]);
        }
    }
    if(!fin)
        res.push_back({begin,end});
    return res;
}

int main() {
    vector<vector<int>> test = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> test1 = {4,8};
    insert(test,test1);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
