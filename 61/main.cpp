#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    ListNode* p1 = head,*tail = head;
    int len = 1;
    while(tail -> next){
        tail = tail -> next;
        len++;
    }
    k = k % len;
    k = len - k;
    if(k == len)
        return head;
    while(k > 1){
        p1 = p1 -> next;
        if(p1 == NULL)
            p1 = head;
        k--;
    }
    tail -> next = head;
    ListNode* res = p1 -> next;
    p1 -> next = nullptr;
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
