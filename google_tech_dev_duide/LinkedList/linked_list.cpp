#include <iostream>

using namespace std;

struct Node
{
    struct Node* prev;
    int data;
    struct Node* next;
};

class LinkedList{
    public:
        Node* head;
        Node* tail;
        int nodeCount;

        LinkedList(){
            head = nullptr;
            tail = nullptr;
            nodeCount = 0;
        }

        void initialize(int val){
            Node* temp = new Node;
            temp->data = val;
            head = temp;
            tail = temp;
            temp->next = temp;
            temp->prev = temp;
        }

        void addAtHead(int val){
            nodeCount++;
            if(!head && !tail){
                initialize(val);
                return;
            }
            else{
                Node* temp = new Node;
                temp->data = val;
                temp->prev = head->prev;
                temp->next = head;
                head->prev->next = temp;
                head->prev = temp;
                head = temp;

            }
        }
        
        void addAtTail(int val){
            nodeCount++;
            if(!head && !tail){
                initialize(val);
                return;
            }
            else{
                Node* temp = new Node;
                temp->data = val;
                temp->prev = tail;
                temp->next = tail->next;
                tail->next->prev = temp;
                tail->next = temp;
                tail = temp;
            }
        }

        void addAtIndex(int index, int val){
            if((!head && !tail) && index==0){
                addAtHead(val);return;
            }
            if(index < 0 or index > nodeCount)return;
            if(index == nodeCount){
                addAtTail(val);
                return;
            }
            if(index == 0){
                addAtHead(val);
                return;
            }
            nodeCount++;
            Node* curr = head;
            if(index < nodeCount/2)     for(int i = 0 ; i < index ; i++) curr = curr->next;
            else    for(int i= 0 ; i < (nodeCount-index) ; i++) curr = curr->prev;
            Node* temp = new Node;
            temp->data = val;
            curr->next->prev = temp;
            temp->prev = curr;
            temp->next = curr->next;
            curr->next = temp;
        }

        void deleteAtIndex(int index){
            if((!head && !tail) or (index < 0 or index > nodeCount-1))  return;
            Node* curr = head;
            for(int i = 1 ;i < index ; i++) curr = curr->next;
            if(index == 0)  curr = tail;
            Node* temp = curr->next;
            Node* next = temp->next;
            next->prev = curr;
            curr->next = next;
            if(index ==0)head = next;
            if(index == nodeCount-1) tail=curr;
            delete temp;
            nodeCount--;
        }
        int get(int index) {
            Node* curr = head;
            if(index < nodeCount/2)     for(int i = 0 ; i < index ; i++) curr = curr->next;
            else    for(int i= 0 ; i < (nodeCount-index) ; i++) curr = curr->prev;
            return curr->data;
        }
};

int main(){
    LinkedList ll;
    ll.addAtHead(2);
    ll.deleteAtIndex(1);
    ll.addAtHead(2);
    ll.addAtHead(7);
    ll.addAtHead(3);
    ll.addAtHead(2);
    ll.addAtHead(5);
    ll.addAtTail(5);
    ll.get(5);
    ll.deleteAtIndex(6);
    cout<<ll.head->data<<endl;
    cout<<ll.tail->data<<endl;
    ll.deleteAtIndex(4);
    int counter = 0;

    cout<<"HEAD<->";
    Node* curr = ll.head;
    while(curr && counter < ll.nodeCount){
        cout<<curr->data<<"<->";
        curr = curr->next;
        counter++;
    }
    cout<<"END"<<endl;
}

// "get","addAtHead","addAtIndex","addAtHead"]
//[4],[4],[5,0],[6]]