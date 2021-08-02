#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if (nums.size() == 0 || k > nums.size())
        return vector<int>(0);
    deque<int> que;
    vector<int> res;
    for(int i = 0; i < k; i++){
        while(!que.empty() && que.back() < nums[i])
            que.pop_back();
        que.push_back(nums[i]);
    }
    res.push_back(que.front());
    for (int j = k ; j < nums.size(); j++){
        if(que.front() == nums[j - k])
            que.pop_front();
        while(!que.empty() && que.back() < nums[j])
            que.pop_back();
        que.push_back(nums[j]);
        res.push_back(que.front());
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
