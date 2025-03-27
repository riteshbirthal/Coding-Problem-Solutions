// User function Template for C++

/*struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution {
  public:
    Node* findFirstNode(Node* head) {
        // your code here
        unordered_set<Node*> u;
        while(head){
            if(u.find(head)!=u.end())
                return head;
            u.insert(head);
            head = head->next;
        }
        return NULL;
    }
};