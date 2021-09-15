#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int maxPoints(vector<vector<int>>& points) {
    unordered_map<double,int> m;
    int res  = 0;
    for(int i = 0; i < points.size(); i++){
        int ini = 0;
        for(int j = 0; j < points.size();j ++){
            if(i == j)
                continue;
            if(points[i][0] == points[j][0]) {
                ini++;
                continue;
            }
            m[(double(points[i][1] - points[j][1])/(points[i][0] - points[j][0]))]++;
            res = max(res, m[(double(points[i][1] - points[j][1])/(points[i][0] - points[j][0]))]);
        }
        res = max(ini,res);
        m.clear();
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
