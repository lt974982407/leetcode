#include <iostream>
#include <vector>

using namespace std;

struct node{
    vector<node*> next;
    bool last;
    node(){
        last = false;
        next.resize(26);
    }
};

class WordDictionary {
public:
    //vector<string> words;
    node* root ;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new node();
    }

    void addWord(string word) {
        node* p = root;
        for(char c : word){
            if(!p -> next[(c - 'a')]){
                p -> next[(c - 'a')] = new node ();
            }
            p = p -> next[(c - 'a')];
        }
        p -> last = true;
    }

    bool dfs(node* root, string word, int index){
        if(index == word.size())
            return root -> last;
        if(word[index] == '.'){
            for(int i = 0; i < 26; i++){
                if(root -> next[i] && dfs(root -> next[i],word,index + 1)){
                     return true;
                }
            }
            return false;
        }
        if(!root -> next[word[index] - 'a']){
            return dfs(root -> next[word[index] - 'a'],word,index + 1);
        }
        return false;
    }

    bool search(string word) {

    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
