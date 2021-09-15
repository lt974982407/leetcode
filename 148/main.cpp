#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* merge(ListNode* l1, ListNode* l2){
    ListNode* fhead = new ListNode(0);
    ListNode* p = fhead;
    while(l1 && l2){
        if(l1 -> val <= l2 -> val){
            p -> next = l1;
            l1 = l1 -> next;
        } else{
            p -> next = l1;
            l2 = l2 -> next;
        }
        p = p -> next;
    }
    p -> next = l1 ? l1 : l2;
    return fhead -> next;
}

ListNode* rec(ListNode* head, ListNode* tail){
    if(head -> next == tail){
        head -> next = nullptr;
        return head;
    }
    ListNode* fast, *slow;
    while(fast != tail){
        fast = fast -> next;
        slow = slow -> next;
        if(fast != tail)
            fast = fast -> next;
    }
    ListNode* l1 = rec(head,slow), *l2 = rec(slow,tail);
    return merge(l1,l2);
}

ListNode* sortList(ListNode* head) {
    if(!head)
        return head;
    return rec(head, nullptr);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
