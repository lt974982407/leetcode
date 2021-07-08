#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getKthFromEnd(ListNode* head, int k) {
    ListNode* p1 = head,*p2 = head;
    if(k == 0|| head == NULL)
        return NULL;
    for (int i = 0; i < k - 1;i++){
        if (p2 == NULL)
            return NULL;
        p2 = p2 -> next;
    }
    while (p2->next != NULL){
        p2 = p2 -> next;
        p1 = p1 -> next;
    }
    return p1;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
