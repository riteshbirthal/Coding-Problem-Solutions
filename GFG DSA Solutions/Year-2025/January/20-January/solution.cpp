/* Link list Node
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
      Node* sortedMerge(Node* head1, Node* head2) {
          // code here
          Node* head, *curr;
          if(head1 && head2){
              (head1->data < head2->data) ? (head = head1, head1 = head1->next) : (head = head2, head2 = head2->next);
              curr = head;
          }else{
              return head1 ? head1 : head2;
          }
          while(head1 || head2){
              if(head1 && head2){
                  (head1->data < head2->data) ? (head->next = head1, head1 = head1->next) : (head->next = head2, head2 = head2->next);
              }else{
                  head1 ? (head->next = head1, head1 = NULL) : (head->next = head2, head2 = NULL);
              }
              head = head->next;
          }
          head = curr;
          return head;
      }
  };