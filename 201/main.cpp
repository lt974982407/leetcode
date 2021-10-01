#include <iostream>

using namespace std;

int rangeBitwiseAnd(int left, int right) {
    /*int tmp = left,tmp1 = right,cnt = 0,cnt1 = 0;
    while(tmp){
        tmp = tmp >> 1;
        cnt ++;
    }
    while(tmp1){
        tmp1 = tmp1 >> 1;
        cnt1 ++;
    }
    if(cnt != cnt1)
        return 0;
    int res = left;
    for(int i = left  ; i <= right && i >> cnt == 0; i++){
        res = i & res ;
        if(i == INT_MAX)
            break;
    }
    return res;*/
    //公共前缀
    int cnt = 0;
    while(left < right){
        left = left >> 1;
        right = right >> 1;
        cnt++;
    }
    return left << cnt;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
