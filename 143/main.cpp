#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void reorderList(ListNode* head) {
    ListNode* p = head;
    while(p && p -> next){
        ListNode* tmp = p;
        while(tmp&& tmp -> next && tmp -> next -> next){
            tmp = tmp -> next;
        }
        tmp -> next -> next = p -> next;
        p -> next = tmp -> next;
        tmp -> next = nullptr;
        p = p -> next -> next;
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
