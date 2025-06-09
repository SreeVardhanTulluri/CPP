#include <iostream>
using namespace std;
class Node{
    public :
    int value;
    Node* next;
    Node* prev;
    
    Node(){
        value = -1;
        next = nullptr;
        prev = nullptr;
    }
    
    Node(Node* aPrev ,int aValue,Node* aNext){
        value = aValue;
        next = aNext;
        prev = aPrev;
    }
};

class MyLinkedList {
public:
    int nodeCount = 0;
    Node *head;
    Node *tail;
    MyLinkedList() {
        Node node;
        head = &node;
        tail = &node;
        head->prev = tail;
        tail->next = head;
    }
    
    int get(int index) {
        Node* curr = head;
        if (index <=nodeCount){
            for(int i=0 ; i<index ; i++)
                curr = head->next;
            return curr->value;
        }
        else    {return -1;}
    }
    
    void addAtHead(int val) {
        if(head->value < 0){
            head->value = val;
            nodeCount++;
            return;
        }
        Node temp(head->prev,val,head);
        head->prev = &temp;
        tail->next = &temp;
        nodeCount++;
    }
    
    void addAtTail(int val) {
        if(tail->value < 0){
            tail->value = val;
            nodeCount++;
            return;
        }
        Node temp(tail,val,tail->next);
        tail->next = &temp;
        head->prev = &temp;
        nodeCount++;
    }
    
    void addAtIndex(int index, int val) {
        addNode(val,getNode(index),getNode(index+1));
    }
    
    void deleteAtIndex(int index) {
        Node* prev = getNode(index-1);
        Node* next = getNode(index+1);
        prev->next = next;
        next->prev = prev;
    }
    void addNode(int val, Node *prev,Node *next ){
        // Node temp(next->prev,val,prev->next);
        // Node* temp =nullptr;
        // prev->next = temp;
        // next->prev = temp;

        //TODO : BUGGED (all lines)
    }
    Node* getNode(int index){
        if(index > nodeCount or index < 0) return nullptr;
        Node* curr;
        if(index < nodeCount/2){
            curr = head;
            for(int i=0 ; i< index; i++){
                curr = curr->next;
            }
        }
        else{
            curr = tail;
            for(int i =0 ; i< nodeCount - index; i++){
                curr = curr->prev;
            }
        }
        return curr;
    }
};


/**
 * Your MyLinkedList object will be instantiated and called as such:
 */

int main(){
    
    MyLinkedList* obj = new MyLinkedList();
    int param_1 = obj->get(2);
    obj->addAtHead(3);
    obj->addAtTail(2);
    obj->addAtIndex(2,3);
    obj->deleteAtIndex(1);
    std::cout<<"hello"<<std::endl;
 }