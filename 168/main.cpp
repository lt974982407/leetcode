#include <iostream>

using namespace std;

string convertToTitle(int columnNumber) {
    string res = "";
    while (columnNumber > 0){
        int col = columnNumber - 1;
        int s = col % 26;
        char addition = 'A' + s;
        res = addition + res;
        columnNumber = col / 26;
    }
    return  res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
