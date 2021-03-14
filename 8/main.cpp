#include <iostream>
#include <string>

using namespace std;

int myAtoi(string s) {
    int index = 0, len = s.size();
    int ans = 0;
    bool flag = true;
    int num = 0;
    while(index < len) {
        if (s[index] == ' ') index++;
        else if (s[index] == '+') { break; }
        else if (s[index] == '-') { break; }
        else if ((s[index] < '0' || s[index] > '9')) return 0;
        else break;
    }
    if (s[index] == '+') index++;
    else if (s[index] == '-') {index++;flag = false;}
    for (;index < len ; index++){
        if(!(s[index] >= '0' && s[index] <='9')) break;
        int tmp = s[index] - '0';
        if((ans > INT_MAX/10 || ans == INT_MAX/10 && tmp >= 7) && flag) {return INT_MAX;  }
        if((ans > INT_MAX/10 || ans == INT_MAX/10 && tmp >= 8) &&!flag ) {return INT_MIN; }
        ans = ans * 10 + tmp;
    }
    if (!flag) ans = -ans;
    return ans;

}

int main() {
    std::cout << myAtoi("-2147483648") << std::endl;
    return 0;
}
