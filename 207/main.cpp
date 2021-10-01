#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graphs(numCourses,vector<int>(numCourses));
    vector<int> pre(numCourses,0);
    queue<int> que;
    int done = 0;
    for(int i = 0; i < prerequisites.size();i++){
        graphs[prerequisites[i][0]][prerequisites[i][1]] = 1;
        pre[prerequisites[i][0]] ++;
    }
    for(int i : pre)
        if(i == 0)
            que.push(i);
    while(!que.empty()){
        int tmp = que.front();
        que.pop();
        done ++;
        for(int i = 0; i <numCourses;i++){
            if(graphs[i][tmp] == 1){
                graphs[i][tmp] = 0;
                pre[i]--;
                if(pre[i] == 0)
                    que.push(i);
            }
        }
    }
    return done == numCourses;
}

int main() {
    int val = 0;
    int x = 13;
    while(x){
        val = val ^ x;
        x = x >> 1;
    }
    cout<<val<<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
