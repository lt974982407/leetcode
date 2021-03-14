#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector <vector<int>>   array(n, vector<int>(n, 0));
    int l = 0, r = n - 1, u = 0, d = n - 1;
    int num = 1, tot = n * n;
    while (num <= tot){
        for (int i = l ; i <= r; i++){
            array[u][i] = num;
            num++;
        }
        u++;
        for (int i = u; i <= d; i++){
            array[i][r] = num;
            num++;
        }
        r--;
        for (int i = r; i >= l; i--){
            array[d][i] = num;
            num++;
        }
        d--;
        for (int i = d; i >= u; i--){
            array[i][l] = num;
            num++;
        }
        l++;
    }
    return array;

}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int len = matrix.size() * matrix[0].size();
    vector<int> res (len,0);
    int l = 0, r = matrix[0].size() - 1, u = 0, d = matrix.size() - 1;
    cout<< r <<' '<<d<<endl;
    int tp = 0;
    while (tp < len){
        for (int i = l ; i <= r; i++){
            res[tp] = matrix[u][i] ;
            tp++;
        }
        u++;
        for (int i = u; i <= d; i++){
            res[tp] = matrix[i][r] ;
            tp++;
        }
        r--;
        for (int i = r; i >= l; i--){
            res[tp] = matrix[d][i] ;
            tp++;
        }
        d--;
        for (int i = d; i >= u; i--){
            res[tp] = matrix[i][l] ;
            tp++;
        }
        l++;
    }
    for (int i = 0; i <res.size();i++ ){
        cout<<res[i]<<' ';
    }
    cout<<endl;
    return res;

}

int numRollsToTarget(int d, int f, int target) {
    if (d == 1){
        if (target > f) return 0;
        else if (target <= f && target >= 0) return 1;
        else if (target <= 0) return 0;
    }
    else{
        int sum = 0;
        for (int k = 1; k <= f; k++){
            //cout<<numRollsToTarget (d - 1, f , target - k) + sum<<endl;
            sum = numRollsToTarget (d - 1, f , target - k) + sum;
        }
        return sum;
    }
    //return 0;
}

int main() {
    vector<vector<int>> s (3,vector<int>(4,0));
    s[0] = {1,2,3,4};
    s [1] = {5,6,7,8};
    s[2] = {9,10,11,12};
    //spiralOrder(s);
    cout<<numRollsToTarget(2,6,7);
    vector<int> a;
    return 0;
}
