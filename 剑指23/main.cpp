#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
    ListNode* p1 = head, *p2 = head;
    while(p2 != NULL){
        if(p2->next == NULL){
            return NULL;
        }
        p1 = p1 -> next;
        p2 = p2 -> next -> next;
        if (p1 == p2){
            ListNode* p3 = head;
            while (p3 != p1){
                p3 = p3 -> next;
                p1 = p1 -> next;
            }
            return p1;
        }
    }
    return NULL;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
