#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
    int len1 = matrix.size();
    if(len1 == 0)
        return 0;
    int len2 = matrix[0].size();
    if(len2 == 0)
        return 0;
    vector<vector<int>> num(len1,vector<int>(len2,0));
    vector<int> up(len1,0),down(len1,0);
    for(int i = 0; i < len1; i++){
        for(int j = 0; j < len2; j++){
            if(matrix[i][j] == '1'){
                num[i][j] = j == 0 ? 1 : num[i][j - 1] + 1;
            }
        }
    }
    int res = 0;
    for(int j = 0; j < len2; j++){
        stack<int> s;
        for(int i = 0 ; i < len1; i++){
            //cout<<'1'<<endl;
            while(!s.empty() && num[s.top()][j] >= num[i][j])
                s.pop();
            up[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        s = stack<int>();
        for(int i = len1 - 1 ; i >= 0; i--){
            while(!s.empty() && num[s.top()][j] >= num[i][j])
                s.pop();
            down[i] = s.empty() ? len1 : s.top();
            s.push(i);
        }
        for(int i = 0; i < len1; i++){
            res = max(res,(down[i] - up[i] - 1) * num[i][j]);
        }
        //cout<<j<<endl;
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
