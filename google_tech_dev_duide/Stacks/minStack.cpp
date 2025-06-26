#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    int min;
    struct Node* next;
};


class MinStack {
public:
    Node* head;
    MinStack() {
        head = nullptr;
    }
    
    void push(int val) {
        if(!head){
            head = new Node;
            head->data = val;
            head->min = val;
            return;
        }
        Node *temp = new Node;
        temp->data = val;
        temp->next = head;
        temp->min = head->min < val ? head->min : val;
        head = temp;
    }
    
    void pop() {
        if(!head)
            return;
        Node* temp = head;
        head = (head->next) ? temp->next : nullptr;
        delete temp;
        return;
    }
    
    int top() {
        return head->data;
    }
    
    int getMin() {
        return head->min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */



int main(){
    MinStack* obj = new MinStack();
    obj->push(2147483646);
    obj->push(2147483646);
    obj->push(2147483647);
    cout<<obj->top()<<endl;
    obj->pop();
    obj->pop();
    cout<<obj->getMin()<<endl;
    obj->pop();
    obj->push(2147483647);
    cout<<obj->top()<<endl;
    cout<<obj->getMin()<<endl;
    obj->push(-2147483648);
    cout<<obj->top()<<endl;
    cout<<obj->getMin()<<endl;
    obj->pop();
    cout<<obj->getMin()<<endl;
    
}
 