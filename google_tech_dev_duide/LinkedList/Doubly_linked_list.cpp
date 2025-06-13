#include<iostream>
using namespace std;
struct Node{
    struct Node *prev = nullptr;
    int val = 0;
    struct Node *next = nullptr;
};

class MyLinkedList {
public:
    Node* head;
    int nodeCount;
    MyLinkedList() {
        head = nullptr;
        nodeCount = -1;
    }
    void initialize(int val){
        Node *temp = new Node;
        temp->val = val;
        head = temp;
    }
    int get(int index) {
        if(!head || index < 0) return -1;
        if(index >= 0 && index <=nodeCount){
            Node *curr = head;
            for(int i=0 ; i< index; i++) curr = curr->next;
            return curr->val;
        }
        return 0;
    }
    
    void addAtHead(int val) {
        nodeCount++;
        if(!head){
            initialize(val);
            return;
        }
        Node *temp = new Node;
        temp->val = val;
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    
    void addAtTail(int val) {
        nodeCount++;
        if(!head){
            initialize(val);
            return;
        }
        Node *curr = head;
        while(curr->next != nullptr) curr = curr->next;
        Node *temp = new Node;
        temp->val = val;
        temp->prev = curr;
        curr->next = temp;
    }
    
    void addAtIndex(int index, int val) {
        if(!head && index==0){
            initialize(val);
            return;
        }
        if(index == 0) {addAtHead(val);return;}
        if(index == nodeCount+1) {addAtTail(val);return;}
        if(index > nodeCount)   return;
        nodeCount++;
        Node *curr = head;
        for(int i = 1 ;i < index ; i++)  curr = curr->next;
        Node *temp = new Node;
        temp->val = val;
        if(curr->next){
            temp->next = curr->next;
            temp->next->prev = temp;

        }
        temp->prev = curr;
        curr->next = temp;
    }
    
    void deleteAtIndex(int index) {
        if(!head or index <0 or index >nodeCount) return;
        if(nodeCount == 0) {delete head;nodeCount--;return;}
        if(index == 0){
            Node *temp = head;
            if(head->next){
                head->next->prev = nullptr;
                head = head->next;
                delete temp;
                nodeCount--;
                return;
            }
        }
        if(index == nodeCount){
            Node *curr = head;
            while(curr->next->next) curr = curr->next;
            Node *temp = curr->next;
            curr->next = nullptr;
            delete temp;
            nodeCount--;
            return;
        }
        Node *curr = head;
        for(int i = 1 ; i < index ; i++) curr = curr->next;
        Node *temp = curr->next;
        temp->next->prev = curr;
        curr->next = temp->next;
        delete temp;      
        nodeCount--;  
    }
};
int main(){
    MyLinkedList* obj = new MyLinkedList();
    // obj->addAtHead(1);
    // obj->addAtHead(3);
    // obj->addAtTail(1);
    // obj->addAtIndex(1,2);
    // obj->deleteAtIndex(1);
    // cout<<obj->get(2)<<endl;
    obj->addAtHead(1);
    obj->deleteAtIndex(0);
    Node *curr = obj->head;
    while(curr){
        cout<<curr->val <<"<->";
        if(!curr->next)break;
        curr = curr->next;
    }
    cout<<"END"<<endl;
    while(curr){
        cout<<curr->val <<"<->";
        curr = curr->prev;
    }
    cout<<"END"<<endl;
}
    