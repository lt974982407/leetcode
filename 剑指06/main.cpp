#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
    };

vector<int> reversePrint(ListNode* head) {
    ListNode* p,* q ;
    p = head;
    q = head;
    int len = 0;
    while (p != NULL){
        len++;
        p = p->next;
    }
    vector<int> res (len,0);
    for (int i = 0; i < len ; i++){
        res[len - i - 1] = q -> val;
        q = q -> next;
    }
    return res;
}

vector<int> reversePrint(ListNode* head) {
    stack<int> node;
    ListNode* p = head;
    while (p != NULL){
        node.push(p -> val);
        p = p -> next;
    }

    vector<int> res;
    while(!node.empty()){
        res.push_back(node.top());
        node.pop();
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
