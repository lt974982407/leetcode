#include <iostream>

using namespace std;

string add(string num1,string num2){
    string res = "";
    int i = num1.size() - 1, j = num2.size() - 1;
    bool flag = false;
    while(i >= 0 && j >= 0){
        int a = num1[i] - '0';
        int b = num2[j] - '0';
        int c = a + b;
        if(flag){
            c++;
            flag = false;
        }
        if(c > 9) {
            flag = true;
            c = c - 10;
        }
        res = to_string(c) + res;
        i--;
        j--;
    }
    if(i < 0 && j >= 0){
        while( j >= 0){
            int b = num2[j] - '0';
            if(flag){
                b++;
                flag = false;
            }
            if(b > 9) {
                flag = true;
                b = b - 10;
            }
            res = to_string(b) + res;
            j--;
        }

    }
    else if(i >= 0 && j <= 0){
        while( i >= 0){
            int b = num1[i] - '0';
            if(flag){
                b++;
                flag = false;
            }
            if(b > 9) {
                flag = true;
                b = b - 10;
            }
            res = to_string(b) + res;
            i--;
        }

    }
    if(flag)
        res = "1" + res;
    return res;
}

string multiply(string num1, string num2) {
    if(num1=="0" || num2 == "0")
        return "0";
    string res = "0";
    for(int i = num2.size() - 1; i >= 0; i--){
        int tmp = 0;
        string bitres = "";
        for(int j = num1.size() - 1; j >= 0; j--){
            int a = num1[j] - '0';
            int b = num2[i] - '0';
            cout<<a<<b<<endl;
            int c = a * b;
            c = c + tmp;
            tmp = c / 10;
            c = c % 10;
            bitres = to_string(c) + bitres;
        }
        if(tmp != 0)
            bitres = to_string(tmp) + bitres;
        //cout<<bitres<<endl;
        for(int k = i; k < num2.size() - 1; k++)
            bitres += "0";
        res = add(res,bitres);
    }
    return res;

}

int main() {
    cout<<multiply("9999","999")<<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
