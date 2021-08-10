#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
    ListNode* fhead = new ListNode (0,head);
    ListNode* p = fhead;
    while( p -> next && p ->next -> next ){
        ListNode* tmp = p -> next;
        p -> next = p -> next -> next;
        tmp -> next = p -> next -> next;
        p -> next -> next = tmp;
        p = p -> next -> next;
    }
    return fhead -> next;

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
