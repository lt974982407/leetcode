#include <iostream>
#include <deque>

using namespace std;

class MaxQueue {
public:
    deque<int> que;
    deque<int> max;
    MaxQueue() {

    }

    int max_value() {
        if(que.empty())
            return -1;
        else
            return max.front();
    }

    void push_back(int value) {
        que.push_back(value);
        while(!max.empty() && value > max.back())
            max.pop_back();
        max.push_back(value);
    }

    int pop_front() {
        if(que.empty())
            return -1;
        int tmp = que.front();
        que.pop_front();
        if(tmp == max.front())
            max.pop_front();
        return tmp;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
