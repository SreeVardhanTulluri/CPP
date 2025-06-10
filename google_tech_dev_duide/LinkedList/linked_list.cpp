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
            if((!head && !tail) or (index < 0 or index > nodeCount))  return;
            nodeCount++;
            Node* curr = head;
            for(int i = 0 ;i < index ; i++) curr = curr->next;
            Node* temp = new Node;
            temp->data = val;
            curr->next->prev = temp;
            temp->prev = curr;
            temp->next = curr->next;
            curr->next = temp;

            //TODO : Add logic to reverse traverse
        }

        void deleteAtIndex(int index){
            if((!head && !tail) or (index < 0 or index > nodeCount))  return;
            Node* curr = head;
            for(int i = 0 ;i < index ; i++) curr = curr->next;

            //TODO |: Add logic to remove node
            //TODO ||: Add logic to reverse traverse
        }
};

int main(){
    LinkedList ll;
    int counter = 0;
    ll.addAtTail(1);
    ll.addAtTail(2);
    ll.addAtTail(4);
    ll.addAtIndex(1,3);
    cout<<"HEAD<->";
    Node* curr = ll.head;
    while(curr && counter < ll.nodeCount){
        cout<<curr->data<<"<->";
        curr = curr->next;
        counter++;
    }
    cout<<"END"<<endl;
}