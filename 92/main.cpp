#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode *fhead = new ListNode (0,head);
    ListNode * p = head, *pre = fhead;
    for(int i = 1; i < left; i++) {
        p = p->next;
        pre = pre -> next;
    }
    //cout<<p->val <<' '<<pre-> val<<endl;
    ListNode* preleft = pre, *curleft = p;
    for(int i = 0; i < right - left + 1; i++){
        ListNode* tmp = p -> next;
        p -> next = pre;
        pre = p;
        p = tmp;
    }
    //cout<<p-> val<<endl;
    curleft -> next = p;
    preleft -> next = pre;
    return fhead -> next;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
