/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode* head2 = NULL, *temp = head->next;
        while(temp){
            head->next = head2;
            head2 = head;
            head = temp;
            temp = temp->next;
        }
        head->next = head2;
        head2 = head;
        temp = head2;
        int carry = 0, num;
        while(temp){
            num = temp->val;
            temp->val = ((2 * num) + carry) % 10;
            carry = ((2 * num) + carry) / 10;
            temp = temp->next;
        }
        head2 = NULL;
        temp = head->next;
        while(temp){
            head->next = head2;
            head2 = head;
            head = temp;
            temp = temp->next;
        }
        if(carry){
            temp = new ListNode(1, head);
            head->next = head2;
            head2 = head;
            head = temp;
        }else{
            head->next = head2;
        }
        return head;
    }
};