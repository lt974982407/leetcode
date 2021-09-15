#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_map<string,int> worldId;
    int num = 0;
    for (int  i = 0;  i < wordList.size(); ++ i) {
        for (int k = 0; k < wordList[i].size(); k++){
            string tmp = wordList[i];
            tmp[k] = '*';
            if(worldId[tmp] == 0){
                num ++;
                cout<<tmp<<num<<endl;
                worldId[tmp] = num;
            }
        }
        if(worldId[wordList[i]] == 0){
            num ++;
            cout<<wordList[i]<<num<<endl;
            worldId[wordList[i]] = num;
        }
    }
    vector<vector<int>> graph(num + 1);
    for (int  i = 0;  i < wordList.size(); ++ i){
        for (int k = 0; k < wordList[i].size(); k++){
            string tmp = wordList[i];
            tmp[k] = '*';
            //cout<<tmp<<endl;
            graph[worldId[tmp]].push_back(worldId[wordList[i]]);
            graph[worldId[wordList[i]]].push_back(worldId[tmp]);
        }
    }
    for(int i = 0 ; i < graph.size(); i++){
        for(int j = 0; j < graph[i].size(); j++)
            cout<<graph[i][j]<<' ';
        cout<<endl;
    }
    if(worldId[endWord] == 0)
        return 0;
    if(beginWord == endWord)
        return 1;
    deque<int> que;
    for(int i = 0; i < beginWord.size(); i++){
        string tmp = beginWord;
        tmp[i] = '*';
        if(worldId[tmp])
            que.push_back(worldId[tmp]);
    }
    int res = 2;
    vector<bool> visited(num + 1, false);
    while(!que.empty()){
        int cnt = que.size();
        for(int i = 0 ; i < cnt; i++){
            int tmp = que.front();
            que.pop_front();
            //cout<<tmp<<endl;
            if(tmp == worldId[endWord])
                return (res + 1)/2;
            for(int index : graph[tmp]) {
                if(!visited[index]){
                    que.push_back(index);
                    visited[index] = true;
                }
            }
        }
        res ++;
    }

    return 0;
}

int main() {
    vector<string> test = {"hot","dog"};
    ladderLength("hot","dog",test);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
