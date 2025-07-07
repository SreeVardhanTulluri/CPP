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

    string returnPrefix(string &word){
        string result = "";
        Node *curr = root;
        for(char c : word){
            if(curr->children.size() <= 0 || curr->children.count(c) == 0 || curr->isEOF){
                break;
            }
            else{
                result += c;
                curr = curr->children[c];
            }     
        }
        return (curr->isEOF) ? result : word;
    }
};


class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        
        Trie *dictTrie = new Trie;
        for(string word : dictionary)
            dictTrie->insert(word); 

        stringstream reader(sentence);
        string word;
        string result;

        while(reader >> word)
            result = result + " " + dictTrie->returnPrefix(word);;
            
        delete dictTrie;
        return result;    
    }
};

int main(){
    Solution *obj = new Solution;
    vector<string> dict = {"cat","bat","rat"};
    string sentence = "the cattle was rattled by the battery";

    cout<<obj->replaceWords(dict,sentence)<<endl;
}