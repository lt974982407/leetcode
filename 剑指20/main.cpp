#include <iostream>
#include <set>

using namespace std;

bool isNumber(string s) {
    int state = 0;
    set<char> num;
    for(int i = 0; i <= 9; i++){
        num.insert(char('0' + i));
    }
    for(int i = 0; i < s.size();i++){
        switch (state) {
            case 0:
                if (s[i] == ' ')
                    state = 0;
                else if (s[i] == '+'||s[i] == '-')
                    state = 1;
                else if (s[i] == '.')
                    state = 9;
                else if (num.find(s[i]) != num.end())
                    state = 2;
                else
                    return false;
                break;
            case 1:
                if (num.find(s[i])!= num.end())
                    state = 2;
                else if (s[i] == '.')
                    state = 9;
                else
                    return false;
                break;
            case 2:
                if (num.find(s[i])!= num.end())
                    state = 2;
                else if (s[i] == '.')
                    state = 3;
                else if (s[i] == ' ')
                    state = 8;
                else if (s[i] == 'e' || s[i] == 'E')
                    state = 5;
                else
                    return false;
                break;
            case 3:
                if (num.find(s[i])!= num.end())
                    state = 4;
                else if (s[i] == 'e' || s[i] == 'E')
                    state = 5;
                else if (s[i] == ' ')
                    state = 8;
                else
                    return false;
                break;
            case 4:
                if (num.find(s[i])!= num.end())
                    state = 4;
                else if (s[i] == 'e' || s[i] == 'E')
                    state = 5;
                else if (s[i] == ' ')
                    state = 8;
                else
                    return false;
                break;
            case 5:
                if (s[i] == '+'|| s[i] == '-')
                    state = 6;
                else if (num.find(s[i])!= num.end())
                    state = 7;
                else
                    return false;
                break;
            case 6:
                if (num.find(s[i])!= num.end())
                    state = 7;
                else
                    return false;
                break;
            case 7:
                if (num.find(s[i])!= num.end())
                    state = 7;
                else if (s[i] == ' ')
                    state = 8;
                else
                    return false;
                break;
            case 8:
                if (s[i] == ' ')
                    state = 8;
                else
                    return false;
                break;
            case 9:
                if(num.find(s[i])!= num.end())
                    state = 4;
                else
                    return false;
                break;
        }
    }
    if (state == 2||state == 3||state == 4||state == 7||state == 8)
        return  true;
    else
        return false;
}

int main() {
    std::cout << isNumber("  .1  ") << std::endl;
    return 0;
}
