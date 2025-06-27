#include <unordered_map>
#include <vector>

#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    vector<Node *> neighbours;
    Node() : val(0){}
    Node(int _val) : val(_val){}
    Node(int _val, vector<Node *> _neighbours) : val(_val) , neighbours(_neighbours){};
};


class Solution{
    public:
    unordered_map<Node*,Node*> visited;
    Node* cloneGraph(Node *node){
        if(!node)   return nullptr;
        if(visited.find(node) != visited.end()) return visited[node];

        Node* cloneNode = new Node(node->val);
        visited[node] = cloneNode;
        for(Node* neighbour : node->neighbours){
            cloneNode->neighbours.push_back(cloneGraph(neighbour));
        }
        return cloneNode;
    }
};