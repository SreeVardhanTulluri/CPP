#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

struct Node{
    char data;
    bool isEOF = false;
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

    string returnCommonPrefix(){
        string result = "";
        Node *curr = root;
        while( curr && curr->children.size() == 1){
            result += curr->data;
            curr = curr->children[curr->children.begin()->first];
        }
        return result+curr->data;;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie *dict = new Trie;
        for(string word : strs)
            dict->insert(word);

        return dict->returnCommonPrefix();
    }
};

int main(){
    vector<string> strs = {"flower","flow","flight"};
    Solution *obj = new Solution();
    cout<<obj->longestCommonPrefix(strs)<<endl;
}