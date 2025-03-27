/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
    public:
      Node* rotate(Node* head, int k) {
          // Your code here
          Node* prev = head;
          int n = 1;
          while(prev->next){
              prev = prev->next;
              n += 1;
          }
          prev->next = head;
          k = k%n;
          for(int i = 0; i < k; i++){
              prev = head;
              head = head->next;
          }
          prev->next = NULL;
          return head;
      }
  };
  