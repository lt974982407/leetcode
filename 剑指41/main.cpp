#include <iostream>
#include <vector>

using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    vector<int> nums;
    MedianFinder() {

    }

    void addNum(int num) {
        if (nums.size() == 0){
            nums.push_back(num);
            return;
        }
        int i;
        for (i = 0; i < nums.size(); i++)
            break;
        nums.insert(nums.begin() + i,num);
    }

    double findMedian() {
        if(nums.size()%2 == 0)
            return ((nums[nums.size()/2] + nums[nums.size()/2-1])/2.0);
        return double(nums[(nums.size() - 1)/2]);
    }
};

int main() {
    vector<int> test = {1,2,3};
    test.insert(test.begin()+3,1);
    for(auto i : test)
        cout<<i<<' ';
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
