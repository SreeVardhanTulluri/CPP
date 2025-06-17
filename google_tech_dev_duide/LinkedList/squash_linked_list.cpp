
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

struct Location{
    public:
    Node *start, *end;

    Location(){
        start = nullptr;
        end = nullptr;
    }
    Location(Node *head, Node *tail){
        start = head;
        end = tail;
    }
};

class Solution{
    public:
    Node *flatten(Node *head){
        if(!head) return nullptr;
        recur_fz(head);
        return head;
    }

    Location *recur_fz(Node *head){
        if(!head)   return nullptr;
        Node *curr = head;
        while(curr){
            if(curr->child){
                Node *start = curr, *end = curr->next;
                Location *loc = recur_fz(start->child);
                Node *subStart = loc->start, *subEnd = loc->end;
                if((start != subStart) || (end != subEnd)){
                    subEnd->next = end;
                    end->prev = subEnd;
                    subStart->prev = start;
                    start->next = subStart;
                    start->child = nullptr;
                    curr = end;
                }
    
            }
            if(curr->next)
                curr = curr->next;
            else
                break;

        }
        return new Location(head,curr);
    }

};