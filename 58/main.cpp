#include <iostream>

using namespace std;

int lengthOfLastWord(string s) {
    int res = 0;
    bool flag = true;
    for (int k = s.size() - 1; k >= 0; k--){
        if (s[k] == ' ' && flag)
            continue;
        else if (s[k] != ' ')
        {
            res++;
            flag = false;
        }
        else if(s[k] == ' ' && !flag)
            break;

    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
