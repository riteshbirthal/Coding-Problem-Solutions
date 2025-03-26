/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
    public:
      Node* mergeKLists(vector<Node*>& arr) {
          // Your code here
          Node* head = new Node(-1), *curr = head;
          int n = arr.size(), idx, val;
          while(true){
              idx = -1, val = INT_MAX;
              for(int i = 0; i < n; i++){
                  if(arr[i] && val>arr[i]->data){
                      idx = i, val = arr[i]->data;
                  }
              }
              if(val==INT_MAX)
                  break;
              curr->next = arr[idx];
              curr = curr->next;
              arr[idx] = arr[idx]->next;
          }
          return head->next;
      }
  };
  