/*structure of a node of the linked list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/
class Solution {
  public:
    bool isLengthEven(struct Node **head) {
        // Code here
        int ans = 0;
        Node *temp = *head;
        while(temp){
            ans++;
            temp = temp->next;
        }
        return ans%2==0;
    }
};