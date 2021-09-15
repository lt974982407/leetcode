#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
    ListNode* p1 = head, * p2 = head;
    while(p1 && p1 -> next){
        p1 = p1 -> next;
        p2 = p2 -> next -> next;
        if(p1 == p2){
            ListNode* tmp = head;
            while(p1 != tmp){
                p1 = p1 -> next;
                tmp = tmp -> next;
            }
            return tmp;
        }
    }
    return nullptr;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
