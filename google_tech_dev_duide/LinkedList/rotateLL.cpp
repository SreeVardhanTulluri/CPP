#include <iostream>
using namespace std;
// Definition for a ListNode.
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode* random;
    
    ListNode(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution {
public:
    ListNode* rotateRight(ListNode *head, int k){
        if(!head) return nullptr;
        if(head->next == nullptr) return head;
        if(head->next->next == nullptr && k%2 == 0) return head;
        
        while(k > 0){
            ListNode *curr = head;
            while(curr->next->next){
                curr = curr->next;
            }
            curr->next->next = head;
            head = curr->next;
            curr->next = nullptr;
            k--;
        }
        return head;
    }
};


int main(){
    ListNode *head = new ListNode(1);
    ListNode *curr = head;
    for(int i =0 ; i < 5 ; i++){
        ListNode *temp = new ListNode(i+2);
        curr->next = temp;
        curr = curr->next;
    }
    head = (new Solution)->rotateRight(head, 3);
    cout << "HEAD->";
    while(head){
        cout<<head->val<<"->";
        head = head->next;
    }
    cout<<"END"<<endl;
}