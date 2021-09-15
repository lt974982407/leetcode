#include <iostream>
#include <vector>

using namespace std;


//超时！！！
int maxProfit1(vector<int>& prices) {
    vector<int> dp(prices.size() + 1,0);
    for(int i = 1; i < prices.size();i ++){
        for(int j = i - 1; j >= 0 ;j --)
            dp[i] = max(dp[i],dp[j] + prices[j + 1] - prices[i]);
    }
    return dp[prices.size() - 1];
}

//不超时的动态规划dp[i][0]表示当天没有股票的最大利润   dp[i][1]表示当天持有股票的最大利润

//贪心算法：

int maxProfit(vector<int>& prices) {
    int res = 0;
    for(int i = 1; i < prices.size(); i++)
        res = res + max(0,prices[i] - prices[i - 1]);
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
