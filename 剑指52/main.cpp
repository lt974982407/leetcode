#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* p1 = headA, *p2 = headB;
    if(p1 == NULL || p2 == NULL)
        return NULL;
    while(p1 != p2){
        if(p1 == NULL)
            p1 = headB;
        else
            p1 = p1 -> next;
        if (p2 == NULL)
            p2 = headA;
        else
            p2 = p2 -> next;
    }
    return p1;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
