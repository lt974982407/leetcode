#include <iostream>
#include <vector>

using namespace std;

int numTrees(int n) {
    vector<int> dp(n + 1,0);
    dp[0] = 1;
    for(int i = 1; i <= n ; i++){
        for(int j = 1; j <= i ; j++ )
            dp[i] = dp[i] + dp[j - 1]* dp[i - j];
    }
    return dp[n];
}

int main() {
    unsigned int  a = 1;
    int b = 2;
    cout << a - b <<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
