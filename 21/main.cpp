#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* p1 = l1, * p2 = l2;
    ListNode* res = new ListNode(0),*p3 = res;
    while(p1 != NULL && p2 != NULL){
        if(p1 -> val < p2 -> val){
            p3 -> next = new ListNode(p1 -> val);
            p1 = p1 -> next;
        }else{
            p3 -> next = new ListNode(p2 -> val);
            p2 = p2 -> next;
        }
        p3 = p3 -> next;
    }
    if(p1 == NULL){
        while (p2 != NULL){
            p3 -> next = new ListNode(p2 -> val);
            p3 = p3 -> next;
            p2 = p2 -> next;
        }
    } else{
        while(p1 != NULL) {
            p3->next = new ListNode(p1->val);
            p3 = p3->next;
            p1 = p1->next;
        }
    }
    return res-> next;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
