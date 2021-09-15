#include <iostream>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> s;
    stack<int> s2;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int val) {
        s.push(val);
        if(s2.empty()){
            s2.push(val);
        }
        else{
            if(s2.top() <= val){
                s2.top();
            }
        }
    }

    void pop() {
        if(!s.empty()){
            int tmp = s.top();
            s.pop();
            if(s2.top() == tmp)
                s2.pop();
        }
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return s2.top();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
