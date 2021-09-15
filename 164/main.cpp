#include <iostream>
#include <vector>


using namespace std;

int maximumGap(vector<int>& nums) {
    int n = nums.size() ;
    if(n < 2)
        return 0;
    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    for(int num : nums){
        minVal = min(num,minVal);
        maxVal = max(num,maxVal);
    }
    int d = max(1,(maxVal - minVal)/(n - 1));
    int size = (maxVal - minVal)/ d + 1;
    vector<pair<int,int>> buf(size,{-1,-1});
    for(int i = 0; i < nums.size(); i++){
        int index = (nums[i] - minVal) / d;
        if(buf[index].first == -1){
            buf[index].first = nums[i];
            buf[index].second =  nums[i];
        }
        else{
            buf[index].first = min(buf[index].first,nums[i]);
            buf[index].second = max(buf[index].second,nums[i]);
        }
    }
    int res = 0;
    int pre = -1;
    for(int i = 0; i < size; i++){
        //cout<<buf[i].first<<' '<<buf[i].second<<endl;
        if (buf[i].first == -1) continue;
        if(pre == -1){
            pre = i;
        }
        else{
            res = max(res,buf[i].first - buf[pre].second);
            pre = i;
        }
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
