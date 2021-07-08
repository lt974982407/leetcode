#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode(0) ,*p = head;
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;
    while(l1 != NULL && l2 != NULL){
        if (l1->val <= l2 ->val){
            p -> next = new ListNode(l1->val);
            l1 = l1 -> next;
        } else{
            p -> next = new ListNode(l2->val);
            l2 = l2 -> next;
        }
        p = p->next;
    }
//    if (l1 == NULL){
//        while (l2 != NULL){
//            p -> next = new ListNode(l2->val);
//            l2 = l2 -> next;
//            p = p->next;
//        }
//    }
//    else if (l2 == NULL){
//        while (l1 != NULL){
//            p -> next = new ListNode(l1->val);
//            l1 = l1 -> next;
//            p = p->next;
//        }
//    }
    if (l1 == NULL)
        p -> next = l2;
    else if (l2 == NULL)
        p -> next = l1;
    //p -> next = NULL;
    return head->next;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
