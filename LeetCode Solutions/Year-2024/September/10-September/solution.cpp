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
    int gcd(int a, int b){
        if(a<b) return gcd(b, a);
        return a%b==0 ? b : gcd(b, a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* head1 = head, *next = head1->next;
        while(next){
            head1->next = new ListNode(gcd(head1->val, next->val), next);
            head1 = head1->next->next;
            next = head1->next;
        }
        return head;
    }
};