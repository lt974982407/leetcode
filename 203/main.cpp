#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeElements(ListNode* head, int val) {
    ListNode* fhead = new ListNode (0,head);
    ListNode* pre = fhead, *cur = head;
    while(cur){
        if(cur -> val == val){
            pre -> next = cur -> next;
            cur = cur -> next;
            continue;
        }
        cur = cur -> next;
        pre = pre -> next;
    }
    return fhead -> next;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
