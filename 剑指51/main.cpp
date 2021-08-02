#include <iostream>
#include <vector>
#include <map>

using namespace std;

int merge (vector<int>& nums, int begin, int end){
    if (begin >= end)
        return 0;
    int mid = (begin + end) / 2;
    int res = merge(nums,begin,mid) + merge(nums,mid + 1,end);
    vector<int> tmp (nums.size(),0);
    for (int i = begin; i <= end; i++)
        tmp[i] = nums[i];
    int m = begin;
    int n = mid + 1;
    for (int k = begin; k <= end; k++){
        if (m == mid + 1){
            nums[k] = tmp[n];
            n++;
        }
        else if (n == end + 1 || tmp[m] <= tmp[n]){
            nums[k] = tmp[m];
            m++;
        }
        else{
            nums[k] = tmp[n];
            n++;
            res += (mid - m + 1);
        }
    }
    return res;
}

int reversePairs(vector<int>& nums) {
    return merge(nums,0,nums.size()-1);
}


int main() {
    vector<int> test = {1,3,2,3,1};
    std::cout << reversePairs(test)<< std::endl;
    return 0;
}
