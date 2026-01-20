/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    Node *flatten(Node *root) {
        // code here
        if(!root)
            return root;
        Node *bottom = flatten(root->bottom);
        Node *next = flatten(root->next);
        Node *curr = root;
        root->next = NULL;
        while(bottom || next){
            if(bottom && next){
                curr->bottom = bottom->data <= next->data ? bottom : next;
                bottom->data <= next->data ? bottom = bottom->bottom : next = next->bottom;
            }else if(bottom){
                curr->bottom = bottom;
                bottom = bottom->bottom;
            }else{
                curr->bottom = next;
                next = next->bottom;
            }
            curr = curr->bottom;
        }
        return root;
    }
};
