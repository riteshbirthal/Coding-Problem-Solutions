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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        ListNode* head1 = head, *temp_head, *next_start;
        int n = 0, parts, extra, nodes = 1;
        while(head1)
            n++, head1 = head1->next;
        parts = n/k;
        extra = n%k;
        head1 = head, temp_head = head;
        for(int i = 0; i < k; i++){
            nodes = 1;
            if(extra){
                for(int j = 1; j < parts+1 && head1; j++){
                    head1 = head1->next;
                }
                extra--;
            }else{
                for(int j = 1; j < parts && head1; j++){
                    head1 = head1->next;
                }
            }
            if(head1)
                next_start = head1->next, head1->next = NULL;
            else
                next_start = NULL;
            ans.push_back(temp_head);
            temp_head = next_start;
            head1 = temp_head;
        }
        return ans;
    }
};