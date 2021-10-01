#include <iostream>
#include <vector>

using namespace std;

void ran(int begin, int end,vector<int>& arr){
    int ran = rand()% (end - begin + 1) + begin;
    int tmp = arr[ran];
    arr[ran] = arr[begin];
    arr[begin] = tmp;
}

int divide(int begin, int end, vector<int>& arr){
    ran(begin,end,arr);
    int tmp = arr[begin];
    while(begin != end){
        while(begin < end && arr[end] <= tmp)
            end--;
        if(begin < end){
            arr[begin] = arr[end];
            begin ++;
        }
        while(begin < end && arr[begin] >= tmp)
            begin++;
        if(begin < end){
            arr[end] = arr[begin];
            end--;
        }
    }
    arr[begin] = tmp;
    return begin;
}

int quickfind(vector<int>& arr,int begin,int end,int k ){
    int corr = divide(begin,end,arr);
    if(corr == k)
        return arr[corr];
    else if(corr > k)
        return quickfind(arr,begin,corr - 1,k);
    else
        return quickfind(arr,corr + 1, end,k);
}



int findKthLargest(vector<int>& nums, int k) {
    return quickfind(nums,9,nums.size() - 1,k);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
