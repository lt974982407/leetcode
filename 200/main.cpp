#include <iostream>
#include <vector>
#include <queue>

using namespace std;


//开始标记不同的内容，但是可能会很大，char溢出，然后造成死循环，直接标记为0就好，如果是int可以这样标记
int numIslands(vector<vector<char>>& grid) {
    queue<pair<int,int>> que;
    int num = 2;
    for(int i = 0; i < grid.size();i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] == '1'){
                que.push({i,j});
                grid[i][j] = ('0' );
                while(!que.empty()){
                    pair<int,int> tmp = que.front();
                    //cout<<tmp.first<<' '<<tmp.second<<endl;
                    que.pop();
                    //grid[tmp.first][tmp.second] = ('0' + num);
                    if(tmp.first > 0 && grid[tmp.first - 1][tmp.second] == '1'){
                        que.push({tmp.first - 1, tmp.second});
                        grid[tmp.first - 1][tmp.second] = ('0' );
                    }
                    if(tmp.second> 0 && grid[tmp.first][tmp.second - 1] == '1'){
                        que.push({tmp.first, tmp.second - 1});
                        grid[tmp.first ][tmp.second - 1] = ('0' );
                    }
                    if(tmp.first < grid.size() - 1 && grid[tmp.first + 1][tmp.second] == '1'){
                        que.push({tmp.first + 1, tmp.second});
                        grid[tmp.first + 1][tmp.second] = ('0' );
                    }
                    if(tmp.second < grid[0].size() - 1 && grid[tmp.first][tmp.second + 1] == '1'){
                        que.push({tmp.first, tmp.second + 1});
                        grid[tmp.first ][tmp.second + 1] = ('0' );
                    }
                }
                num ++;
            }
        }
    }
    return num - 2;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
