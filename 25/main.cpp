#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool ver(ListNode* p,int k){
    for(int i = 0; i < k ; i++){
        if(p)
            p = p -> next;
        else
            return false;
    }
    return true;
}

ListNode* reverse(ListNode* p,int k,ListNode*& h){
    ListNode* pre = p, * cur = p -> next;
    for(int i = 0; i < k; i++){
        ListNode* tmp = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = tmp;
    }
    h = pre;
    return cur;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode * fhead = new ListNode (0,head);
    ListNode* p = fhead;
    while (ver(p,k)){
        ListNode* p1 = p -> next;
        ListNode* pre;
        ListNode* p2 = reverse(p,k,pre);
        p -> next = pre;
        p1 -> next = p2;
        p = pre;
    }
    return fhead-> next;

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
