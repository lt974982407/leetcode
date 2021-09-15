#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    if(!head)
        return nullptr;
    Node*  p = head;
    Node*  res = new Node (head -> val);
    unordered_map<Node*, Node*>m;
    m[head] = res;
    while(p -> next){
        Node* tmp = new Node (p -> next -> val);
        m[p -> next] = tmp;
        m[p] -> next = tmp;
        p = p -> next;
    }
    p = head;
    while(p){
        if(p -> next)
            m[p] -> next = m[p -> next];
        p = p -> next;
    }
    return res;

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
