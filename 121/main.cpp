#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int res = 0, minnum = prices[0];
    for(int i = 0; i < prices.size(); i++){
        res = max(res, prices[i] - minnum);
        minnum = min(minnum,prices[i]);
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
