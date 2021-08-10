#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergetwo(ListNode* p1 , ListNode* p2){
    ListNode* res = new ListNode (0),*p3 = res;
    while(p1 != NULL && p2 != NULL){
        if(p1 -> val <= p2 -> val){
            p3 -> next = new ListNode (p1 -> val);
            p3 = p3 -> next;
            p1 = p1 -> next;
        }
        else{
            p3 -> next = new ListNode (p2 -> val);
            p3 = p3 -> next;
            p2 = p2 -> next;
        }
    }
    if(p1 == NULL){
        while (p2 != NULL){
            p3 -> next = new ListNode (p2 -> val);
            p3 = p3 -> next;
            p2 = p2 -> next;
        }
    } else{
        while (p1 != NULL){
            p3 -> next = new ListNode (p1 -> val);
            p3 = p3 -> next;
            p1 = p1 -> next;
        }
    }
    return res -> next;
}

ListNode* merge(vector<ListNode*>& lists, int l,int r ){
    if(l > r)
        return NULL;
    if(l == r)
        return lists[l];
    int mid = (l + r)/2;
    return mergetwo(merge(lists,l,mid), merge(lists,mid + 1,r));

}

ListNode* mergeKLists(vector<ListNode*>& lists) {
   return merge(lists,0,lists.size() -1);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
