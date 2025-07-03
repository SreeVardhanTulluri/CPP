#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node *left, *right;

    Node(int n){
        data = n;
    }
};

class Tree{

private:

void addNode(Node *parent, int val){
    if(val > parent->data){
        if(parent->right == nullptr)
            parent->right = new Node(val);
        else
            addNode(parent->right, val);
    }
    else{
        if(parent->left == nullptr)
            parent->left = new Node(val);
        else
            addNode(parent->left,val);
    }
}
public:
    Node *root;
    void insert(int val){
        if(!root){
            root = new Node(val);
        }
        else{
            addNode(root,val);
        }

    }
    bool find(int val){
        Node *ptr = root;
        while(ptr){
            cout<<ptr->data<<"->";
            if(ptr->data == val)
                return true;
            else if(ptr->data > val)
                ptr = ptr->left;
            else if(ptr->data < val)
                ptr = ptr->right;
        }
        return false;
    }

};

int main(){
    Tree *tree = new Tree;
    tree->insert(10);
    tree->insert(12);
    tree->insert(2);
    tree->insert(8);
    tree->insert(6);

    tree->find(8);
    cout<<endl;
}