#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    ListNode * p = head ;
    if (p == NULL)
        return head;
    int num = head -> val;
    while(p -> next != NULL){
        if (p ->next -> val == num){
            p -> next = p -> next -> next;
        }
        else{
            num = p ->next -> val;
            p = p -> next;
        }
    }
    return head;

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
