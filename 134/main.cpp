#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int len = gas.size();
    int index = 0;
    while(index < len){
        int gasnum = 0;
        int costnum = 0;
        int cnt = 0;
        while(cnt < len){
            int j = (index + cnt) % len;
            gasnum += gas[j];
            costnum += cost[j];
            if(costnum > gasnum){
                break;
            }
            cnt ++;
        }
        if(cnt == len)
            return index;
        else
            index = index + cnt + 1;
    }
    return - 1;

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
