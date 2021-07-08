#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int len = popped.size();
    stack<int> s;
    int index = 0;
    for(int i = 0; i < len; i++){
        s.push(pushed[i]);
        while(s.empty()&&s.top() == popped[index]){
            s.pop();
            index++;
        }
    }
    return index == len;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
