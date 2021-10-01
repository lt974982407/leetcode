#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> res;
    vector<unordered_set<int>> con (numCourses);
    vector<unordered_set<int>> con1 (numCourses);
    queue<int> que;
    for(int i = 0 ; i < prerequisites.size(); i++){
        con[prerequisites[i][0]].insert(prerequisites[i][1]);
        //con1[prerequisites[i][1]].insert(prerequisites[i][0]);
    }
    for(int i = 0; i < numCourses; i++){
        if(con[i].size() == 0)
            que.push(i);
    }
    while(!que.empty()){
        int tmp = que.front();
        que.pop();
        res.push_back(tmp);
        for(int i = 0; i < numCourses; i++){
            if(con[i].find(tmp) != con[i].end()) {
                con[i].erase(tmp);
                if(con[i].size() == 0)
                    que.push(i);
            }
        }
    }
    if(res.size() == numCourses)
        return res;
    return {};
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
