#include <iostream>
#include <unordered_map>

using namespace std;

struct Node{
    char data;
    bool isEOF;
    unordered_map<char, Node*> children;

    Node(){};
    Node(char data) : data(data), isEOF(false){};
    Node(char data, bool isEOF) : data(data), isEOF(isEOF){};
};

class Trie {
public:
    Node *root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *curr = root;
        for(char c : word){
            if(curr->children.size() <= 0 || curr->children.count(c) == 0){
                curr->children[c] = new Node(c);
                curr = curr->children[c];
            }
            else
                curr = curr->children[c];
        }
        curr->isEOF = true;
    }
    
    bool search(string word) {
        Node *curr = root;
        for(char c : word){
            if(curr->children.size() <= 0 || curr->children.count(c) == 0)
                return false;
            else
                curr = curr->children[c];
        }
        return curr->isEOF;
    }
    
    bool startsWith(string prefix) {
        Node *curr = root;
        for(char c : prefix){
            if(curr->children.size() <= 0 || curr->children.count(c) == 0)
                return false;
            else
                curr = curr->children[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

 int main(){
    Trie *obj = new Trie();
    // obj->insert("apple");
    // cout<<obj->search("apple")<<endl;
    // cout<<obj->search("app")<<endl;
    // obj->startsWith("app");
    // obj->insert("app");
    // cout<<obj->search("app")<<endl;
    cout<<obj->search("a")<<endl;
 }