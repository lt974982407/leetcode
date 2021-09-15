#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* p1 = headA ,*p2 = headB;
    while(p1 && p2){
        if(p1 == p2)
            return p1;
        p1 = p1 -> next;
        p2 = p2 -> next;
    }
    ListNode* p3 = p1 ? headA : headB, * p4 = p1 ? p1 : p2,*p5 = p2 ? headA : headB;
    while(p4){
        p3 = p3 -> next;
        p4 = p4 -> next;
    }
    while(p3 && p5){
        if(p3 == p5)
            return p3;
        p3 = p3 -> next;
        p5 = p5 -> next;
    }
    return nullptr;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
