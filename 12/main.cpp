#include <iostream>
#include <vector>

using namespace std;

string intToRoman(int num) {
    vector<char> tmp = {'I','V','X','L','C','D','M'};
    string res = "";
    int index = 0;
    while(num > 0){
        int mod = num % 10;
        string bit = "";
        if(mod == 0)
            ;
        else if(mod <= 3){
            for(int i = 0; i < mod; i++)
                res = tmp[2 * index] + res;
        }
        else if(mod == 4){
            res = tmp[2 * index + 1] + res;
            res = tmp[2 * index] + res;

        }
        else if (mod == 5){
            res = tmp[2 * index + 1] + res;
        }
        else if (mod >=6 && mod <= 8){
            for(int i = 6; i <= mod; i++)
                res = tmp[2 * index] + res;
            res = tmp[2 * index + 2] + res;
        }
        else{
            res = tmp[2 * index + 2] + res;
            res = tmp[2 * index] + res;
        }
        num = num / 10;
        index ++;
    }
    cout<<res<<endl;
    return res;

}

int main() {
    int a = 300 ;
    a = a / 10;
    intToRoman(300);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
