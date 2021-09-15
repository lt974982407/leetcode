#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* insertionSortList(ListNode* head) {
    if(!head)
        return nullptr;
    ListNode* fhead = new ListNode(0);
    fhead -> next = head;
    ListNode* p = head -> next, *last = head;
    while(p){
        if(last -> val <= p -> val){
            last = p;
            p = p -> next;
        }else{
            ListNode* pre = fhead;
            while(pre -> next -> val <= p -> val)
                pre = pre -> next;
            last -> next = p -> next;
            p -> next = pre -> next;
            pre -> next = p;
        }
        p = last -> next;
    }
    return fhead -> next;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
