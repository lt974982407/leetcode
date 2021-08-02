#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> findContinuousSequence(int target) {
    vector<vector<int>> res;
    vector<int> tmp;
    int count = 0;
    for (int i = 0; i < target/2 + 1; i++){
        count = count + i;
        tmp.push_back(i);
        if (count == target)
            res.push_back(tmp);
        else if(count > target){
            while (count > target){
                count -= tmp[0];
                tmp.erase(tmp.begin());
            }
            if (count == target)
                res.push_back(tmp);
        }
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
