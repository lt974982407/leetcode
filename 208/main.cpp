#include <iostream>
#include <vector>

using namespace std;

struct node{
    char val;
    vector<node*> next;
    node(char c){
        val = c;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    node* fhead;
    //vector<node*> words;
    Trie() {
        fhead = new node ('1');
        fhead -> next = {};
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        int index = 0;
        node* pre = nullptr,* cur = fhead;
        while(pre != cur && index < word.size()){
            pre = cur;
            for(int i = 0; i < cur -> next.size();i++){
                if(cur -> next[i] -> val == word[index]){
                    cur = cur -> next[i];
                    index ++;
                }
            }
        }
        while(index < word.size()){
            node* tmp = new node (word[index]);
            cur -> next.push_back(tmp);
            index ++;
            cur = cur -> next[cur -> next.size() - 1];
        }
        cur -> next.push_back(new node ('-'));
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        int index = 0;
        node* pre = nullptr,* cur = fhead;
        while(pre != cur && index < word.size()){
            pre = cur;
            for(int i = 0; i < cur -> next.size();i++){
                if(cur -> next[i] -> val == word[index]){
                    cur = cur -> next[i];
                    index ++;
                }
            }
        }
        if(index == word.size()){
            for(int i = 0; i < cur -> next.size();i++){
                if(cur -> next[i] -> val == '-'){
                    return true;
                }
            }
        }
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int index = 0;
        node* pre = nullptr,* cur = fhead;
        while(pre != cur && index < prefix.size()){
            pre = cur;
            for(int i = 0; i < cur -> next.size();i++){
                if(cur -> next[i] -> val == prefix[index]){
                    cur = cur -> next[i];
                    index ++;
                }
            }
        }
        return index == prefix.size();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
