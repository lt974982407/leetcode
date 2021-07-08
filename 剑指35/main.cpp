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
        return NULL;
    Node* p = head;
    unordered_map<Node*,Node*> hash;
    while(p){
        hash[p] = new Node (p -> val);
        p = p -> next;
    }
    p = head;
    while(p){
        if(p -> next){
            hash[p] -> next = hash[p -> next];
        } else
            hash[p] -> next = NULL;
        if(p -> random){
            hash[p] -> random = hash[p -> random];
        } else
            hash[p] -> random = NULL;
    }
    return hash[head];

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
