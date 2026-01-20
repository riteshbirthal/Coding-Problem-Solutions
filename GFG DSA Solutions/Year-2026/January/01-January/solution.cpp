/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
        unordered_set<Node*> u;
        while(head1){
            u.insert(head1);
            head1 = head1->next;
        }
        while(head2){
            if(u.find(head2)!=u.end())
                return head2;
            head2 = head2->next;
        }
        return NULL;
    }
};
