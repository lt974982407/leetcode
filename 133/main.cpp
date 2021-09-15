#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

Node* cloneGraph(Node* node) {
    unordered_map<Node*,Node*> m;
    unordered_map<Node*,bool> m1;
    deque<Node*> que;
    que.push_back(node);
    while(!que.empty()){
        Node* tmp = que.front();
        que.pop_front();
        if(m1[tmp])
            continue;
        m1[tmp] = true;
        if(m[tmp] == nullptr){
            m[tmp] = new Node (tmp -> val);
        }
        for(int i = 0; i < tmp ->neighbors.size(); i++){
            if(m[tmp -> neighbors[i]] == nullptr)
                m[tmp -> neighbors[i]] = new Node (tmp -> neighbors[i] -> val);
            m[tmp] -> neighbors.push_back(m[tmp -> neighbors[i]]);
            que.push_back(tmp -> neighbors[i]);
        }
    }
    return m[node];
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
