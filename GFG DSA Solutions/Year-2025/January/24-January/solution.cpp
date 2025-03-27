// User function template for C++

/*

struct Node
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
      // Function to check if the linked list has a loop.
      bool detectLoop(Node* head) {
          // your code here
          unordered_set<Node*> u;
          while(head){
              if(u.find(head)!=u.end()) return true;
              u.insert(head);
              head = head->next;
          }
          return false;
      }
  };
  
  