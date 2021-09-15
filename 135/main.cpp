#include <iostream>
#include <vector>

using namespace std;

int candy(vector<int>& ratings) {
    vector<int> left(ratings.size(),1);
    left[0] = 1;
    for(int i = 1; i < ratings.size(); i++){
        if(ratings[i] > ratings[i - 1]){
            left[i] = left[i - 1] + 1;
        }
    }
    int right = 1, res = left[ratings.size() - 1];
    for(int i = int(ratings.size() - 2); i >= 0; i--){
        if(ratings[i] > ratings[i + 1])
            right = right + 1;
        else
            right = 1;
        res = res + max(right,left[i]);
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
