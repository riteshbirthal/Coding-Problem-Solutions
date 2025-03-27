/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
    public:
      Node *reverseList(Node* head){
          Node* prev = NULL, *curr = head, *next;
          while(curr){
              next = curr->next;
              curr->next = prev;
              prev = curr;
              curr = next;
          }
          return prev;
      }
      
      Node *reverseKGroup(Node *head, int k) {
          // code here
          Node* curr = head, *prev = new Node(-1), *temp;
          prev->next = head;
          head = prev;
          int n = 1;
          while(curr){
              if(n%k==0){
                  temp = curr->next;
                  curr->next = NULL;
                  prev->next = reverseList(prev->next);
                  while(prev->next){
                      prev = prev->next;
                  }
                  prev->next = temp;
                  curr = prev;
              }
              curr = curr->next;
              n += 1;
          }
          if(curr!=prev){
              temp = NULL;
              prev->next = reverseList(prev->next);
              while(prev->next){
                  prev = prev->next;
              }
              prev->next = temp;
              curr = prev;
          }
          return head->next;
      }
  };
  