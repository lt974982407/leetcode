#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void solve(vector<vector<char>>& board) {
    int m = board.size(), n = board[0].size();
    deque<int> que;
    for(int i = 0; i < n ; i++){
        if(board[0][i] == 'O'){
            que.push_back(0);
            que.push_back(i);
        }
    }
    for(int i = 0; i < n ; i++){
        if(board[m - 1][i] == 'O'){
            que.push_back(m - 1);
            que.push_back(i);
        }
    }
    for(int i = 1; i < m - 1 ; i++){
        if(board[i][0] == 'O'){
            que.push_back(i);
            que.push_back(0);
        }
    }
    for(int i = 1; i < m - 1 ; i++){
        if(board[i][n - 1] == 'O'){
            que.push_back(i);
            que.push_back(m - 1);
        }
    }
    while(!que.empty()){
        int a = que.front();
        que.pop_front();
        int b = que.front();
        que.pop_front();
        if(board[a][b] == 'O'){
            board[a][b] = 'o';
            if(a > 0 && board[a - 1][b] == 'O'){
                que.push_back(a - 1);
                que.push_back(b);
            }
            if(a < m - 1&& board[a + 1][b] == 'O'){
                que.push_back(a + 1);
                que.push_back(b);
            }
            if(b > 0 &&board[a][b - 1] == 'O'){
                que.push_back(a );
                que.push_back(b - 1) ;
            }
            if(b < n - 1&& board[a][b + 1] == 'O'){
                que.push_back(a );
                que.push_back(b + 1);
            }

        }
    }
    for(int i = 0; i < m ; i++){
        for(int j = 0; j < n ; j++){
            if(board[i][j] == 'o')
                board[i][j] = 'O';
            else if(board[i][j] == 'O' )
                board[i][j] = 'X';
        }
    }
}

int main() {
    vector<vector<char>> test = {{'O','X','X','O','X'},{'X','O','O','X','O'},{'X','O','X','O','X'},{'O','X','O','O','O'},{'X','X','O','X','O'}};
    solve(test);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
