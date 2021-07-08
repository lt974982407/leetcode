#include <iostream>

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

void midorder(Node* curr,Node*& pre,Node*& head){
    if(!curr)
        return;
    midorder(curr->left,pre,head);
    if(pre != NULL)
        pre -> right = curr;
    else
        head = curr;
    curr -> left = pre;
    pre = curr;
    midorder(curr -> right , pre,head);
}

Node* treeToDoublyList(Node* root){
    if(!root)
        return NULL;
    Node* head = NULL,*pre= NULL;
    midorder(root,pre,head);
    head -> left = pre;
    pre -> right = head;
    return head;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
