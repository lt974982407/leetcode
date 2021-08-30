#include <iostream>

using namespace std;

bool isNumber(string s) {
    int state = 0;
    for(int i = 0; i < s.size(); i++){
        switch (state) {
            case 0 :
                if(s[i] == '+' || s[i] == '-')
                    state = 1;
                else if(s[i] >= '0' && s[i] <= '9')
                    state = 2;
                else if(s[i] == '.')
                    state = 8;
                else
                    return false;
                break;
            case 1 :
                if(s[i] >= '0' && s[i] <= '9')
                    state = 2;
                else if(s[i] == '.')
                    state = 8;
                else
                    return false;
                break;
            case 2:
                cout<<2<<endl;
                if(s[i] >= '0' && s[i] <= '9')
                    state = 2;
                else if(s[i] == 'e' || s[i] == 'E')
                    state = 5;
                else if(s[i] == '.')
                    state = 3;
                else
                    return false;
                break;
            case 3:
                if(s[i] >= '0' && s[i] <= '9')
                    state = 4;
                else if(s[i] == 'e' || s[i] == 'E')
                    state = 5;
                else
                    return false;
                break;
            case 4:
                if(s[i] >= '0' && s[i] <= '9')
                    state = 4;
                else if(s[i] == 'e' || s[i] == 'E')
                    state = 5;
                else
                    return false;
                break;
            case 5:
                if(s[i] == '-' || s[i] == '+')
                    state = 6;
                else if(s[i] >= '0' && s[i] <= '9')
                    state = 7;
                else
                    return false;
                break;
            case 6:
                if(s[i] >= '0' && s[i] <= '9')
                    state = 7;
                else
                    return false;
                break;
            case 7:
                if(s[i] >= '0' && s[i] <= '9')
                    state = 7;
                else
                    return false;
                break;
            case 8:
                if(s[i] >= '0' && s[i] <= '9')
                    state = 4;
                else
                    return false;
                break;
        }
    }
    cout<<state<<endl;
    return state == 2 || state == 3 || state == 4 || state == 7;
}

int main() {
    isNumber("1e.");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
