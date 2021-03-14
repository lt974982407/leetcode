#include <iostream>
#include <vector>
using namespace std;

int reverse(int x) {
    vector<int> arr;
    int ans = 0;
    while (x != 0){
        arr.push_back(x-x/10*10);
        x=x/10;
    }
    for (int i = 0; i< arr.size(); i++){
        if(ans > INT_MAX/10 || ans < INT_MIN/10) return 0;
        ans = ans*10 + arr[i];
    }
    return ans;

}
int main() {
    cout << reverse(-735);
    return 0;
}
