#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteNode(ListNode* head, int val) {
    ListNode* p = head;
    while (p!=NULL ){
        if (p->val == val)
            break;
        else
            p = p -> next;
    }
    if(p -> next == NULL){
        ListNode* q = head;
        if (q == p){
            head = NULL;
            return head;
        }
        while (q -> next != p){
            q = q -> next;
        }
        p -> next = p -> next -> next;
    }
    else{
        int num = p -> next -> val;
        p -> next = p -> next -> next;
        p -> val = num;
    }
    return  head;

}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
