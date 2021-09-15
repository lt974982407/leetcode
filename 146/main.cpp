#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

//class LRUCache {
//private:
//    unordered_map<int,int> store;
//    unordered_map<int,int> record;
//    queue<int> que;
//    int maxlen;
//    int curlen;
//public:
//    LRUCache(int capacity) {
//        maxlen = capacity;
//        curlen = 0;
//    }
//
//    int get(int key) {
//        if(store.find(key) == store.end())
//            return -1;
//        record[key] ++;
//        que.push(key);
//        return store[key];
//    }
//
//    void put(int key, int value) {
//        if(store.find(key) != store.end()) {
//            store[key] = value;
//            record[key] ++;
//            que.push(key);
//            return ;
//        }
//        if(curlen < maxlen){
//            store[key] = value;
//            curlen ++;
//            que.push(key);
//        }
//        else{
//            int tmp = que.front();
//            que.pop();
//            while(record[tmp] != 0){
//                //cout<<'h'<<tmp<<endl;
//                record[tmp]--;
//                tmp = que.front();
//                //cout<<tmp<<endl;
//                que.pop();
//            }
//            cout<<tmp<<endl;
//            store.erase(tmp);
//            store[key] = value;
//            que.push(key);
//        }
//    }
//};

struct node{
    node* pre;
    node* next;
    int key;
    int value;
    node(int a = 0,int b = 0){
        key = a;
        value = b;
        pre = nullptr;
        next = nullptr;
    }
};

class LRUCache {
private:
    int size;
    int cursize;
    node* head, * tail;
    unordered_map<int , node* >m;
public:
    LRUCache(int capacity) {
        size = capacity;
        cursize = 0;
        head = new node(0,0);
        tail = new node ();
        head -> next = tail;
        tail -> pre = head;
    }

    int get(int key) {
        if(m.find(key) == m.end()){
            return -1;
        }
        else{
            node* tmp = m[key] ;
            tmp -> pre -> next = tmp -> next;
            tmp -> next -> pre = tmp -> pre;
            tmp -> pre = tail -> pre;
            tail -> pre -> next = tmp;
            tmp -> next = tail;
            tail -> pre = tmp;
            return m[key] -> value;
        }
    }

    void put(int key, int value) {
        if(m.find(key) != m.end()){
            m[key] -> value = value;
            get(key);
            return;
        }
        node* tmp = new node (key,value);
        tmp -> pre = tail -> pre;
        tail -> pre -> next = tmp;
        tmp -> next = tail;
        tail -> pre = tmp;
        if(size == cursize){
            node* del = head -> next;
            m.erase(del -> key);
            head -> next = del -> next;
            del -> next -> pre = head;
            delete del;
        }else{
            cursize++;
        }
        m[key] = tmp;
        cout<<head -> next -> value<<endl;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
