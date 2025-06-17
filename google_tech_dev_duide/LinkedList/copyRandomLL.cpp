#include <iostream>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        Node *curr = head;
        while(curr){
            Node *tmp = new Node(curr->val);
            tmp->next = curr->next;
            curr->next = tmp;
            curr = tmp->next;
        }
        curr = head;
        while(curr){
            if(curr->random)
            curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
        curr = head;
        Node *result = head->next;
        while(curr && (curr->next->next)){
            Node *temp = curr->next->next;
            curr->next->next = temp->next;
            curr->next = temp;
            curr = temp;
        }

        return result;
    }
};


int main(){
    Node *head = new Node(1);
    Node *curr = head;
    for(int i =0 ; i < 5 ; i++){
        Node *temp = new Node(i+2);
        curr->next = temp;
        curr = curr->next;
    }
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    // cout<<(new Solution)->copyRandomList(nullptr)<<endl;
    Node *newHead = (new Solution)->copyRandomList(head);
    cout << "HEAD->";
    while(newHead){
        cout<<newHead->val<<"->";
        newHead = newHead->next;
    }
    cout<<"END"<<endl;
}