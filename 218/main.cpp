#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b)
    {
        if(b.second == a.second)
            return b.first > a.first;
        else
            return b.second > a.second;
    }
};

vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> que;
    int index = 0;
    vector<vector<int>> res;
    vector<int> edge;
    for(int i = 0; i < buildings.size(); i++){
        edge.push_back(buildings[i][0]);
        edge.push_back(buildings[i][1]);
    }
    sort(edge.begin(),edge.end());
    for(int i = 0; i < edge.size(); i++){
        while(index < buildings.size() && buildings[index][0] <= edge[i]){
            que.push({buildings[index][1], buildings[index][2]});
            index++;
        }
        while(!que.empty() && que.top().first <= edge[i])
            que.pop();
        int height = que.empty() ? 0 : que.top().second;
        if(res.empty() || res.back()[1] != height)
            res.push_back({edge[i],height});
    }
    return res;
}


int main() {
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> que;
    que.push({1,2});
    que.push({2,0});
    que.push({30,28});
    que.push({50,1});
    cout<<que.top().second<<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
