#include <iostream>
#include <queue>

using namespace std;

class MyStack {
private:
    queue<int> que1,que2;
public:
    MyStack() {
    }

    void push(int x) {
        que2.push(x);
        while(!que1.empty()){
            que2.push(que1.front());
            que1.pop();
        }
        queue<int> tmp = que1;
        que1 = que2;
        que2 = tmp;
    }

    int pop() {
        if(que1.empty())
            return 0;
        int res = que1.front();
        que1.pop();
        return res;
    }

    int top() {
        if(que1.empty())
            return  0;
        return que1.front();
    }

    bool empty() {
        return que1.empty();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
