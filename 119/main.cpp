#include <iostream>
#include <vector>

using namespace std;

vector<int> getRow(int rowIndex) {
    vector<int> res (rowIndex,1);
    for(int i = 3; i <= rowIndex; i++){
        int pre = 1;
        for(int j = 1; j < rowIndex - 1; j ++){
            res[j] = pre + res[j];
            pre = res[j] - pre;
        }
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
