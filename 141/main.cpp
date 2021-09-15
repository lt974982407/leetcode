#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    ListNode* p1 = head, * p2 = head;
    while(p2 && p2 -> next){
        p1 = p1 -> next;
        p2 = p2 -> next;
        p2 = p2 -> next;
        if(p1 == p2)
            return true;
    }
    return false;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
