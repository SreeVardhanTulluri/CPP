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
        if(index == 0) addAtHead(val);
        if(index == nodeCount) addAtTail(val);
        if(index > nodeCount)   return;
        nodeCount++;
        Node *curr = head;
        for(int i = 1 ;i < index ; i++)  curr = curr->next;
        Node *temp = new Node;
        temp->val = val;
        temp->next = curr->next;
        temp->next->prev = temp;
        temp->prev = curr;
        curr->next = temp;
    }
    
    void deleteAtIndex(int index) {
        if(!head || index < 0 || index > nodeCount) return;
        Node *curr = head;
        if(index == nodeCount){
            while(curr->next->next) curr = curr->next;
            Node *temp = curr->next;
            curr->next = nullptr;
            delete temp;
        }
        for(int i = 1 ;i < index ; i++)  curr = curr->next;
        Node *temp = curr->next;
        curr->next = temp->next;
        curr->next->prev = temp->prev;
        delete temp;
        nodeCount--;
    }
};
#include<iostream>
using namespace std;
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
    cout<<obj->nodeCount<<endl;
    for(int i=0;i<=obj->nodeCount;i++){
        cout<<obj->get(i)<<"<->";
    }
}
    