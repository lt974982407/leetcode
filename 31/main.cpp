#include <iostream>
#include <vector>

using namespace std;

void nextPermutation(vector<int>& nums) {
    for(int i = nums.size() - 1; i >= 0 ; i --){
        int tmp = nums[i];
        int k = i;
        while(k + 1 < nums.size()){
            if(nums[k] > nums[k + 1]){
                int temp = nums[k];
                nums[k] = nums[k + 1];
                nums[k+ 1] = temp;
                k++;
            }
            else
                break;
        }
        for(int index : nums)
            cout<<index<<' ';
        cout<<endl;
        if(i > 0 && tmp > nums[ i - 1]){
            for(int t = i ; t < nums.size(); t++){
                if(nums[t] > nums[ i - 1]){
                    int temp = nums[t];
                    nums[t] = nums[i - 1];
                    nums[i - 1] = temp;
                    return;
                }
            }
        }

    }

}

int main() {
    vector<int> test = {2,3,1};
    nextPermutation(test);
    for(int index : test)
        cout<<index<<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
