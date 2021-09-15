#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

ListNode* getmid(ListNode* start, ListNode* end){
    ListNode* slow = start, *fast = start;
    while(fast != end && fast -> next != end){
        slow = slow -> next;
        fast = fast -> next;
        fast = fast -> next;
    }
    return slow;
}


TreeNode* rec(ListNode* start , ListNode* end){
    if(start == end)
        return nullptr;
    ListNode* mid = getmid(start,end);
    TreeNode* p = new TreeNode (mid -> val);
    p -> left = rec(start,mid);
    p -> right = rec(mid -> next,end);
    return p;
}

TreeNode* sortedListToBST(ListNode* head) {
    return rec(head, nullptr);
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
