#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* p1 = head, *p2 = head;
    for(int i = 0; i < n; i++){
        if(p2 == NULL)
            return NULL;
        p2 = p2 -> next;
    }
    if(p2 == NULL)
        return head -> next;
    ListNode* pre = NULL;
    while(p2 != NULL){
        pre = p1;
        p1 = p1 -> next;
        p2 = p2 -> next;
    }
    pre -> next = p1 -> next;
    return head;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
