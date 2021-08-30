#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* partition(ListNode* head, int x) {
    ListNode* fhead = new ListNode(0,head);
    ListNode *ch = fhead;
    while(ch -> next && ch -> next -> val < x)
        ch = ch -> next;
    if(!ch -> next)
        return head;
    ListNode* p = ch -> next,* pre = ch;
    while(p){
        if(p -> val < x){
            ListNode* tmp = p;
            pre -> next = p -> next;
            p -> next = ch -> next;
            ch -> next = p;
            ch = p;
            p = pre -> next;
            continue;
        }
        p = p -> next;
        pre = pre -> next;
    }
    return fhead -> next;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
