#include <iostream>
#include <vector>

using namespace std;

int getSum (int index){
    int res = 0;
    while(index != 0){
        res += index % 10;
        index = index / 10;
    }
    return res;
}
void check(int m,int n,int k, int x,int y, int& num,vector<vector<int>>& visited);

int movingCount(int m, int n, int k) {
    int res = 0;
    vector<vector<int>> visited(m,vector<int>(n,0));
    check(m,n,k,0,0,res,visited);
    return res;
}

void check(int m,int n,int k, int x,int y, int& num,vector<vector<int>>& visited){
    if (x < 0 || y < 0 || x >= m || y >= n || k < (getSum(x)+ getSum(y)) || visited[x][y] == 1)
        return;
    else{
        visited[x][y] = 1;
        num ++;
        check(m,n,k,x+1,y,num,visited);
        check(m,n,k,x,y+1,num,visited);
    }

}



int main() {
    std::cout << movingCount(3,2,17) << std::endl;
    return 0;
}
