#include <iostream>

using namespace std;

string addBinary(string a, string b) {
    int i = a.size() - 1, j = b.size() - 1;
    int flag = 0;
    string res = "";
    while(i >= 0 && j >= 0){
        int bita = a[i] - '0';
        int bitb = b[j] - '0';
        res =  to_string(bita ^ bitb ^ flag) + res;
        flag = (bita & bitb ) | (flag & (bita | bitb));
        i--;
        j--;
    }
    if(i >= 0 && j < 0){
        while(i >= 0){
            int bita = a[i] - '0';
            res =  to_string(bita  ^ flag) + res;
            flag = bita & flag;
            i--;
        }
    }
    else if(i < 0 && j >= 0){
        while(j >= 0){
            int bitb = b[j] - '0';
            res =  to_string(bitb ^ flag) + res;
            flag = bitb & flag;
            j--;
        }
    }
    if(flag)
        res = "1" + res;
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
