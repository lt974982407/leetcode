#include <iostream>
#include <vector>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    vector<vector<int>> row (9,vector<int>(9,0));
    vector<vector<int>> box (9,vector<int>(9,0));
    for(int i = 0 ; i < board.size(); i++){
        vector<int> col(9,0);
        for(int k = 0; k < board[0].size(); k++){
            if(board[i][k] == '.')
                continue;

            if(col[board[i][k]-'1'] != 0)
                return false;
            //cout<<i<<k<<endl;
            if(row[k][board[i][k]-'1'] != 0)
                return false;
            if(box[i / 3 * 3 + k / 3][board[i][k]-'1'] != 0)
                return false;
            col[board[i][k]-'1']++;
            row[k][board[i][k]-'1']++;
            box[i / 3 * 3 + k / 3][board[i][k]-'1']++;
        }
        //col.clear();
    }
    return true;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
