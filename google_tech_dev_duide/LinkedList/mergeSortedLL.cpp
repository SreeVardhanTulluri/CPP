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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!(list1 && list2))
            return (!list1)? list2 : list1;
        ListNode *curr1 = list1, *curr2 = list2;
        ListNode *result = new ListNode(), *rEnd = result;
        while(curr1 && curr2){
            if(curr1->val < curr2->val){
                rEnd->next = curr1;
                curr1 = curr1->next;  
            }
            else{
                rEnd->next = curr2;
                curr2 = curr2->next;
            }
            rEnd = rEnd->next;
        }
        rEnd->next = (!curr1)? curr2 : curr1;
        return result->next;
    }
};

int main(){
    ListNode* list1 = new ListNode(1,(new ListNode(2,(new ListNode(3,(new ListNode(4)))))));
    // ListNode* list2 = new ListNode(2,(new ListNode(3,(new ListNode(4,(new ListNode(5)))))));
    ListNode* list2 = nullptr;

    ListNode* result = (new Solution)->mergeTwoLists(list1,list2);
    while(result){
        cout<<result->val<<"->";
        result = result->next;
    }
    cout<<"END"<<endl;
}