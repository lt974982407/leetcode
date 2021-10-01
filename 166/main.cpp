#include <iostream>
#include <unordered_map>

using namespace std;

string fractionToDecimal(int numerator, int denominator) {
    if(denominator == 0)
        return "";
    string res = "";
    if(numerator > 0 && denominator < 0 || numerator < 0 && denominator > 0)
        res += '-';
    long long num1 = numerator, num2 = denominator;
    num1 = num1 > 0 ? num1 : -num1;
    num2 = num2 > 0 ? num2 : -num2;
    res = res + to_string((num1 / num2));
    if(num1 % num2 == 0){
        return res;
    }
    num1 = num1 % num2;
    res = res + '.';
    unordered_map<long long,int> m;
    string tmp;
    while(num1 % num2 != 0){
        if(m.find(num1) != m.end())
            return res + tmp.substr(0,m[num1]) +'(' + tmp.substr(m[num1]) + ')';
        num1 = num1 * 10;
        tmp = tmp + to_string(num1/num2);
        num1 = num1 % num2;
    }
    res = res + tmp;
    return res;

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
