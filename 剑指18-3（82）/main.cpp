#include <iostream>
#include <set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* phead ;
    phead -> next = head;
    ListNode* p = phead;
    set<int> num;
    ListNode* q = head;
    while (q -> next!= NULL){
        if (q -> val == q -> next -> val){
            num.insert(q -> val);
        }
        q = q -> next;
    }
    while (p -> next!= NULL){
        if (num.find(p -> next -> val) != num.end()){
            p -> next = p -> next -> next;
            continue;
        }
        p = p -> next;
    }

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
