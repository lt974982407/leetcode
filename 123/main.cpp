#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int buy1 = -prices[0],buy2 = -prices[0],sell1 = 0,sell2 = 0;
    for(int i = 1; i < prices.size();i++){
        buy1 = max(buy1,-prices[i]);
        sell1 = max(sell1,buy1 + prices[i]);
        buy2 = max(buy2,sell1 - prices[i]);
        sell2 = max(sell2,buy2 + prices[i]);
    }
    return sell2;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
