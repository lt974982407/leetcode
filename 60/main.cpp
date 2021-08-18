#include <iostream>
#include <vector>

using namespace std;

string getPermutation(int n, int k) {
    int stairmul = 1;
    vector<int> tmp;
    string res = "";
    for(int i = 1 ; i <= n ; i++) {
        stairmul *= i;
        tmp.push_back(i);
    }
    stairmul /= n;
    k--;
    while(n > 0){
        int index = (k ) / stairmul;
        cout<<index<<endl;
        res = res + to_string(tmp[index]);
        tmp.erase(tmp.begin() + index);
        k = k % stairmul;
        n--;
        if(n > 0)
            stairmul /= n;
    }
    return res;
}

int main() {
    cout<<getPermutation(3,1)<<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
