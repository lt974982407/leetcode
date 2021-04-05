#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    /*int num = 0;
    int len1 = m;
    for (int i = 0; i < len1; i++){
        if (num == n) return;
        if(nums1[i] > nums2[num]){
            for(int j = len1 - 1; j >= i;j--){
                nums1[j+1] = nums1[j];
            }
            len1++;
            nums1[i] = nums2[num];
            num++;
        }
    }
    if(num < n){
        while (num < n){
            nums1[len1] = nums2[num];
            num++;
            len1++;
        }
    }*/
    int p1 = m - 1, p2 = n -1;
    int cur = m + n - 1;
    while(p1 >= 0|| p2 >= 0){
        if(p1 < 0){
            nums1[cur] = nums2[p2];
            cur--;
            p2--;
        }
        else if(p2 < 0){
            nums1[cur] = nums1[p1];
            p1--;
            cur--;
        }
        else if(nums1[p1]>nums2[p2]){
            nums1[cur] = nums1[p1];
            p1--;
            cur--;
        }
        else{
            nums1[cur] = nums2[p2];
            cur--;
            p2--;
        }
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
