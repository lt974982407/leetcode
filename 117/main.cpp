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
    Node* start = root;
    while(start ){
        Node* nextline = nullptr, *pre = nullptr;
        for(Node* p = start; p != nullptr; p = p -> next){
            if(p -> left){
                if(pre)
                    pre -> next = p -> left;
                if(!nextline)
                    nextline = p -> left;
                pre = p -> left;
            }
            if(p -> right){
                if(pre)
                    pre -> next = p -> right;
                if(!nextline)
                    nextline = p -> right;
                pre = p -> right;
            }
        }
        //cout<<start -> val <<endl;
        start = nextline;
    }
    return root;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
