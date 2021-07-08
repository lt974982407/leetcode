#include <iostream>

class MinStack {
public:
    /** initialize your data structure here. */
    struct node{
        int val;
        node* next;
        int minval;
        node(int x){val = x;next = NULL;}
        ~node(){}
    };
    node* head;
    int len;
    MinStack() {
        head = NULL;
        len = 0;
    }

    void push(int x) {
        if(len == 0){
            head = new node (x);
            head -> minval = x;
            len++;
        } else{
            node* tmp = new node (x);
            tmp -> minval = std::min(x,head ->val);
            tmp -> next = head;
            head = tmp;
            len++;
        }

    }

    void pop() {
        if(len != 0){
            node* tmp = head;
            head = head -> next;
            delete(head);
            len--;
        }
    }

    int top() {
        return head-> val;
    }

    int min() {
        return  head->minval;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
