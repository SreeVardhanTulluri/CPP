#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !(head->next)) return head;
        ListNode *curr = head;
        while(curr && curr->next){
            ListNode* temp = curr->next;
            curr->next = temp->next;
            temp->next = head;
            head = temp;
        }
        return head;
    }
};

int main(){
    ListNode* head = new ListNode(1,(new ListNode(2,(new ListNode(3,(new ListNode(4)))))));
    ListNode* curr = (new Solution)->reverseList(head);
    while(curr){
        cout<<curr->val<<"->";
        curr = curr->next;
    }
    cout<<"END"<<endl;
}