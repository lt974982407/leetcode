#include <iostream>
#include <stack>

using namespace std;

class CQueue {
public:
    stack<int> stack1,stack2;
    CQueue() {

    }

    void appendTail(int value) {
        stack1.push(value);
    }

    int deleteHead() {
        if (stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if(stack2.empty())
            return -1;
        int res = stack2.top();
        stack2.pop();
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
