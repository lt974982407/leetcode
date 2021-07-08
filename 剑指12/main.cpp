#include <iostream>
#include <vector>

using namespace std;
bool check(vector<vector<char>>& board, string word,int i,int j,int index,vector<vector<int>>& visited);
bool check1(vector<vector<char>>& board, string word,int i,int j,int index,vector<vector<int>>& visited,vector<vector<int>>& tword);
bool exist(vector<vector<char>>& board, string word) {
    int len1 = board.size() ;
    if (len1 == 0)
        return false;
    int len2 = board[0].size() ;
    if (len2 == 0)
        return false;
    vector<vector<int>> visited (len1,vector<int>(len2,0));
    for (int i = 0; i< len1 ;i++){
        for (int j = 0; j < len2 ;j ++){
           if (check(board,word,i,j,0,visited))
               return true;
        }
    }
    return false;

}

bool check(vector<vector<char>>& board, string word,int i,int j,int index,vector<vector<int>>& visited){
    bool res = false;
    cout<<board[i][j]<<endl;
    if (word[index] != board[i][j])
        return false;
    else if (word[index] == board[i][j] && index == word.length() - 1)
        return true;
    else {
        visited[i][j] = 1;
        res = (i != 0 && visited[i-1][j] == 0 && check(board,word,i-1,j,index+1,visited)) || (i != board.size() - 1 && visited[i+1][j] == 0 && check(board,word,i+1,j,index+1,visited)) || (j != 0 && visited[i][j - 1] == 0 && check(board,word,i,j-1,index+1,visited)) || (j != board[0].size() -1 && visited[i][j+1] == 0 && check(board,word,i,j+1,index+1,visited));
    }
    visited[i][j] =0;
    return res;
}

vector<vector<vector<int>>> ans;

bool exist1(vector<vector<char>>& board, string word) {
    int len1 = board.size() ;
    if (len1 == 0)
        return false;
    int len2 = board[0].size() ;
    if (len2 == 0)
        return false;
    vector<vector<int>> visited (len1,vector<int>(len2,0));
    for (int i = 0; i< len1 ;i++){
        for (int j = 0; j < len2 ;j ++){
            vector<vector<int>> tmp;
            check1(board,word,i,j,0,visited,tmp);
        }
    }
    for (int m = 0; m < ans.size();m++){
        for (int n = 0; n < ans[m].size();n ++){
            cout<<ans[m][n][0]<<' '<<ans[m][n][1]<<endl;
        }
        cout<<endl;
    }
    return false;

}

bool check1(vector<vector<char>>& board, string word,int i,int j,int index,vector<vector<int>>& visited,vector<vector<int>>& tword){
    bool res = false;
    //cout<<board[i][j]<<endl;
    if (word[index] != board[i][j])
        return false;
    else if (word[index] == board[i][j] && index == word.length() - 1) {
        tword.push_back({i,j});
        ans.push_back(tword);
    }
    else {
        visited[i][j] = 1;
        tword.push_back({i,j});
        res = (i != 0 && visited[i-1][j] == 0 && check1(board,word,i-1,j,index+1,visited,tword)) || (i != board.size() - 1 && visited[i+1][j] == 0 && check1(board,word,i+1,j,index+1,visited,tword)) || (j != 0 && visited[i][j - 1] == 0 && check1(board,word,i,j-1,index+1,visited,tword)) || (j != board[0].size() -1 && visited[i][j+1] == 0 && check1(board,word,i,j+1,index+1,visited,tword));
    }
    visited[i][j] =0;
    //if (res == false){
        tword.pop_back();
    //}
    return res;
}


int main() {
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    //vector<vector<char>> board ={{'A'}};
    cout<<exist1(board,"BFSA");
    return 0;
}
