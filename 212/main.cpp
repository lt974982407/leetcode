#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

//两种方法都超时，要用前缀树orz
/*
bool dfs( vector<vector<char>> board, vector<vector<bool>>visited, string target,int index,int row, int col){
    if(row < 0 || row > board.size() - 1 || col < 0 || col > board[0].size() - 1 || visited[row][col])
        return false;
    if(board[row][col] != target[index])
        return false;
    if(index + 1 == target.size()){
        return true;
    }
    visited[row][col] = true;
    return dfs(board,visited,target,index + 1,row - 1,col)|| dfs(board,visited,target,index + 1,row + 1,col)||dfs(board,visited,target,index + 1,row,col - 1)|| dfs(board,visited,target,index + 1,row,col + 1);
}


vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> res;
    vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(), false));
    for(string word : words){
        bool flag = false;
        for(int i = 0; i < board.size();i++){
            for(int j = 0; j < board[0].size();j++){
                flag = dfs(board,visited,word,0,i,j);
                if (flag){
                    res.push_back(word);
                    break;
                }
                if(flag)
                    break;
            }
        }
    }
    return res;
}*/
unordered_set<string> s;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

void dfs(vector<string>& res,vector<vector<char>> board,vector<vector<bool>> visited,int row,int col,string tmp, int maxlen){
    if(  tmp.size() >= maxlen)
        return ;
    tmp = tmp + board[row][col];
    if(s.find(tmp) != s.end()){
        res.push_back(tmp);
        s.erase(tmp);
        return;
    }
    visited[row][col] = true;
    for(int i = 0 ; i < 4; i++){
        int nrow = row + dx[i];
        int ncol = col + dy[i];
        if(nrow < 0 || nrow > board.size() - 1 || ncol < 0 || ncol > board[0].size() - 1 || visited[nrow][ncol])
            continue;
        dfs(res,board,visited,nrow,ncol,tmp,maxlen);
    }
//    dfs(res,board,visited,row - 1,col,tmp,maxlen);
//    dfs(res,board,visited,row + 1,col,tmp,maxlen);
//    dfs(res,board,visited,row,col - 1,tmp,maxlen);
//    dfs(res,board,visited,row,col + 1,tmp,maxlen);
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words){
    vector<string> res;
    vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(), false));
    int maxlen = 0;
    for(string word : words){
        maxlen = max(maxlen, (int)word.size());
        s.insert(word);
    }
    for(int i = 0; i < board.size();i++){
        for(int j = 0; j < board[0].size();j++){
           dfs(res,board,visited,i,j,"",maxlen);
        }
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
