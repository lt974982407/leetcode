#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    bool flag = true;
    for(int i = digits.size() - 1; i >= 0; i--){
        if(flag){
            digits[i] ++;
            flag = false;
            if(digits[i] == 10){
                digits[i] = 0;
                flag = true;
            } else
                return digits;
        }
    }
    if (flag)
        digits.insert(digits.begin(),1);
    return digits;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
