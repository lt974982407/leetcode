#include <iostream>
#include <vector>

using namespace std;
bool flag = true;

void dfs(vector<vector<char>>& board,int pos,vector<vector<int>>col,vector<vector<int>> row,vector<vector<int>> box,vector<vector<int>> visited){
    if(pos == 81){
        flag = false;
        return ;
    }
    int i = pos / 9, j = pos % 9;
    if(visited[i][j]){
        for(int k = 0 ; k < 9; k++){
            if(flag && col[i][k] && row[j][k] && box[i/3*3 + j / 3][k]){
                char a = '1' + k;
                cout<< a<<' '<<i<<' '<<j<<endl;
                board[i][j] = a;
                col[i][k] = 0;
                row[j][k] = 0;
                box[i/3*3 + j / 3][k] = 0;
                dfs(board,pos + 1,col,row,box,visited);
                col[i][k] = 1;
                row[j][k] = 1;
                box[i/3*3 + j / 3][k] = 1;
                //board[i][j] = '.';
            }
        }
    } else
        dfs(board,pos + 1,col,row,box,visited);

}

void solveSudoku(vector<vector<char>>& board) {
    vector<vector<int>>col (9,vector<int>(9,1));
    vector<vector<int>>row (9,vector<int>(9,1));
    vector<vector<int>>box (9,vector<int>(9,1));
    vector<vector<int>>visited(9,vector<int>(9,0));
    for(int i = 0; i < 9 ; i++){
        for(int j = 0; j < 9; j++){
            if(board[i][j] != '.'){
                col[i][board[i][j] - '1'] = 0;
                row[j][board[i][j] - '1'] = 0;
                box[i/3*3 + j / 3][board[i][j] - '1'] = 0;
            }
            else
                visited[i][j] = 1;
        }
    }
    dfs(board,0,col,row,box,visited);
}

int main() {
    vector<vector<char>> test = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    solveSudoku(test);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
