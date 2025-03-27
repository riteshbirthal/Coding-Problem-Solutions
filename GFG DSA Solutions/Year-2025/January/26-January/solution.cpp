/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        // code here
        unordered_set<Node*> u;
        while(head){
            if(u.find(head->next)!=u.end())
                head->next = NULL;
            u.insert(head);
            head = head->next;
        }
    }
};