/* Link list Node
struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};*/

class Solution {
    public:
      Node *cloneLinkedList(Node *head) {
          // Write your code here
          Node* newHead = new Node(-1), *curr = newHead;
          vector<Node*> vec;
          map<Node*, int> mp;
          map<int, Node*> newMp;
          int num = 1;
          while(head){
              curr->next = new Node(head->data);
              mp[head] = num;
              newMp[num] = curr->next;
              vec.push_back(head->random);
              head = head->next;
              curr = curr->next;
              num += 1;
          }
          curr = newHead->next;
          num = 0;
          while(curr){
              curr->random = newMp[mp[vec[num]]];
              curr = curr->next;
              num += 1;
          }
          return newHead->next;
      }
  };
  