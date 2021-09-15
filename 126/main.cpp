#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

unordered_map<string,int> wordId;
vector<vector<int>> graph2;

void dfs(vector<vector<string>>& res ,vector<string> tmp,vector<string> wordList,int index, int target){
    tmp.push_back(wordList[index - 1]);
    if(target == index){
        res.push_back(tmp);
        return;
    }
    for(int i = 0 ; i < graph2[index].size(); i++){
        //cout<<graph2[index][i]<<endl;
        dfs(res,tmp,wordList,graph2[index][i],target);
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    int num = 0;
    for (int  i = 0;  i < wordList.size(); ++ i) {
        wordId[wordList[i]] = i + 1;
    }
    if(wordId[beginWord] == 0) {
        wordId[beginWord] = wordList.size() + 1;
        wordList.push_back(beginWord);
    }
    unordered_map<string,vector<int>> dic;
    for(int i = 0; i < wordList.size(); i++){
        for(int j = 0; j < wordList[i].size(); j++){
            string tmp = wordList[i];
            tmp[j] = '*';
            dic[tmp].push_back(wordId[wordList[i]]);
        }
    }
    vector<vector<int>> graph(wordList.size() + 2);
    graph2.resize(wordList.size() + 2);
    for(unordered_map<string,vector<int>> ::iterator it = dic.begin();it != dic.end(); ++it){
        for(int i = 0 ; i < it -> second.size(); i++){
            for(int j = 0 ; j < it -> second.size();j++){
                if(i != j){
                    //graph[it -> second[i]].push_back(it -> second[j]);
                    graph[it -> second[j]].push_back(it -> second[i]);
                }
            }
        }
    }
    deque<int> que;
    vector<bool> visited(wordList.size() + 2, false);
    que.push_back(wordId[beginWord]);
    visited[wordId[beginWord]] = true;
    bool flag = false;
    while (!que.empty()){
        int cnt = que.size();
        unordered_set<int> visited2;
        for(int i = 0; i < cnt; i++){
            int tmp = que.front();
            que.pop_front();
            for(int j = 0; j < graph[tmp].size(); j++){
                if(!visited[graph[tmp][j]] || graph[tmp][j] == wordId[endWord]){
                    //cout<<graph[tmp][j]<<' ';
                    graph2[tmp].push_back(graph[tmp][j]);
                    visited2.insert(graph[tmp][j]);
                    if(graph[tmp][j] == wordId[endWord]){
                        flag = true;
                    }
                }
            }

        }
        for(int index : visited2) {
            visited[index] = true;
            que.push_back(index);
        }
        //cout<<endl;
        if(flag)
            break;
    }
//    for(int i = 0; i< graph2.size(); i++){
//        for(int j = 0; j < graph2[i].size(); j++)
//            cout<<graph2[i][j]<<' ';
//        cout<<endl;
//    }
    vector<vector<string>> res;
    if(wordId[endWord] == 0)
        return {};
    dfs(res,{},wordList,wordId[beginWord],wordId[endWord]);
    return res;

}

int main() {
    vector<string> test = {"ted","tex","red","tax","tad","den","rex","pee"};
    cout<<findLadders("red","tax",test).size();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
