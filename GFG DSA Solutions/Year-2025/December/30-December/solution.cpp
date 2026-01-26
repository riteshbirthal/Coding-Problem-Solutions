/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* reverseList(Node* head){
        Node* prev = NULL, *curr = head, *next;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        num1 = reverseList(num1);
        num2 = reverseList(num2);
        Node* head = new Node(-1), *curr = head;
        int carry = 0, num;
        while(num1 || num2){
            if(num1 && num2){
                num = num1->data + num2->data + carry;
                num1 = num1->next;
                num2 = num2->next;
            }else if(num1){
                num = num1->data + carry;
                num1 = num1->next;
            }else{
                num = num2->data + carry;
                num2 = num2->next;
            }
            curr->next = new Node(num%10);
            carry = num/10;
            curr = curr->next;
        }
        if(carry)
            curr->next = new Node(1);
        head = reverseList(head->next);
        while(head && head->data==0){
            head = head->next;
        }
        return head ? head : new Node(0);
        
    }
};

