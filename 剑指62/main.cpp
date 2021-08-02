#include <iostream>
#include <vector>

using namespace std;

int lastRemaining(int n, int m) {
//    vector<int> tmp(n,0);
//    int index = 0;
//    int count = 0;
//    int t = m;
//    while(count < n - 1){
//        if(index == n)
//            index = 0;
//        if(tmp[index] == 0)
//            t--;
//        if(t == 0){
//            tmp[index] = 1;
//            t = m;
//            count ++;
//        }
//        index++;
//    }
//    for(int i = 0; i < n; i++)
//        if(tmp[i]== 0)
//            return i;
//    return 0;
    int res = 1;
    for(int i = 2;i <= n; i++){
        res = (res + m) % i;
    }
    return res;
}

int main() {
    cout<<lastRemaining(5,3)<<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
