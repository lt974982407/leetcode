#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a , int b){
    return b ? gcd(b , a % b) : a;
}

void rotate(vector<int>& nums, int k) {
    k = k % nums.size();
    //int cnt = gcd(nums.size(),k);
    int cnt = 0;
    for(int start = 0; start < nums.size(); start++){
        int cur = start, curval = nums[start];
        while(true){
            int tmp = curval;
            curval = nums[(cur + k) % nums.size()];
            nums[(cur + k) % nums.size()] = tmp;
            cur = (cur + k) % nums.size();
            cnt++;
            if(cur == start)
                break;
        }
        if(cnt == nums.size())
            break;
    }
}

/*
unsigned floatScale2(unsigned uf) {
    if(uf == 0x7f800000 || uf == 0xff800000 || uf == 0x80000000){
        return uf;
    }
    if(uf >> 31 == 1){
        cout<<"h"<<endl;
        uf = ((1 << 31) - 1) & uf;
        unsigned a = uf + uf;
        a = a | (1 << 31);
        return a;
    }
    return uf + uf;
}

int floatFloat2Int(unsigned uf) {
    int res;
    int index = uf >> 23;
    cout<<index<<endl;
    index = index & 0xff;
    cout<<index<<endl;
    index = index - 127;
    cout<<(index > 0xf7)<<endl;
    if(index < 0){
        //cout<<'j'<<endl;
        return 0;
    }else if(index >= (0xf7)){
        //cout<<'j'<<endl;
        return  0x80000000u;
    }
    else if (index >= 0xf6){
        //cout<<'j'<<endl;
        res = (1 << 23) - 1;
        res = res & uf;
        res = res << (index - 23);
        res = res | (1 << 30);
    }else{
        //cout<<'j'<<endl;
        res = (1 << 23) - 1;
        res = res & uf;
        res = res >> (23 - index);
        res = res | (1 << index);
    }
    if(uf >> 31 == 1){
        res = ~res + 1;
    }
    return res;
}*/

int main() {
    //int x = -9;
    //int c = x | ((~x + 1) >> 31);
    //cout<<c<<endl;
    //cout<<floatFloat2Int(0x7effffff)<<endl;
    //cout<<int (1.2)<<endl;
    char c = 127;
    int a = (int) c;
    std::cout << a << std::endl;
    return 0;
}
