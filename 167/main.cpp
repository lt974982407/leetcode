#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int begin = 0 , end = numbers.size() - 1;
    while(begin < end){
        int sum = numbers[begin] + numbers[end];
        if(sum == target  )
            return {begin,end};
        else if(sum < target)
            begin ++;
        else
            end --;
    }
    return {};
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
