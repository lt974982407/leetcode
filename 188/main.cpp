#include <iostream>
#include <vector>

using namespace std;

int maxProfit(int k, vector<int>& prices) {
    if(prices.size() == 0 || k == 0)
        return 0;
    vector<vector<int>> buy(k,vector<int>(prices.size(),-prices[0])),sold(k,vector<int>(prices.size(),0));
    for(int i = 1; i < prices.size(); i++){
        buy[0][i] = max(buy[0][i - 1],- prices[i]);
        sold[0][i] = max(buy[0][i - 1] + prices[i], sold[0][i - 1]);
        for(int j = 1; j < k; j++){
            buy[j][i] = max(sold[j - 1][i - 1] - prices[i], buy[j][i - 1]);
            sold[j][i] = max(buy[j][i - 1] + prices[i], sold[j][i - 1]);
        }
    }
    return sold[k - 1][prices.size() - 1];
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
