#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root) {
    if(!root )
        return nullptr;
    Node* start = root;
    while(start -> left){
        for(Node* p = start; p != nullptr; p = p -> next){
            p -> left -> next = p -> right;
            if(p -> next)
                p -> right -> next = p -> next -> left;
        }
        //cout<<start -> val <<endl;
        start = start -> left;
    }
    return root;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
