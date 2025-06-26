struct Node
{
    int data;
    struct Node *next;
};


class MyCircularQueue {
public:
    int size, pos = -1;
    Node *front, *rear;

    MyCircularQueue(int k) {
        size = k;
    }
    
    bool enQueue(int value) {
        if(!(front && rear)){
            front = rear = new Node;
            rear->data = value;
            pos++;
            return true;
        }
        if(!(isFull())){
            Node *temp = new Node;
            temp->data = value;
            Node *curr = front;
            for(int i = 0 ; i < pos ; i++)
                curr = curr->next;
            temp->next = curr->next;
            curr->next = temp;
            return true;
        }
        else{
            pos = 0;
            return enQueue(value);
        }       
        return false;
    }
    
    bool deQueue() {
        if(!(isEmpty())){
            Node *temp = front;
            front = front->next;
            delete temp;
            pos--;
            return true;
        }
        return false;
    }
    
    int Front() {
        if(front)
            return front->data;
        return -1;
    }
    
    int Rear() {
        if(rear)
            return rear->data;
        return -1;
    }
    
    bool isEmpty() {
        return pos<0;
    }
    
    bool isFull() {
        return pos == size-1;
    }
};

#include <iostream>
using namespace std;

int main(){
    MyCircularQueue* obj = new MyCircularQueue(3);
    bool param_1 = obj->enQueue(1);
    bool param_2 = obj->enQueue(2);
    bool param_3 = obj->enQueue(3);
    bool param_4 = obj->enQueue(4);
    int param_5 = obj->Rear();
    bool param_6 = obj->isFull();
    bool param_7 = obj->deQueue();
    bool param_8 = obj->enQueue(4);
    int param_9 = obj->Rear();

    cout<<param_1<<endl<<param_2<<endl<<param_3<<endl;
    cout<<param_4<<endl<<param_5<<endl<<param_6<<endl;
    cout<<param_7<<endl<<param_8<<endl<<param_9<<endl;
}
// Your MyCircularQueue object will be instantiated and called as such:
// int param_3 = obj->Front();
// bool param_5 = obj->isEmpty();

