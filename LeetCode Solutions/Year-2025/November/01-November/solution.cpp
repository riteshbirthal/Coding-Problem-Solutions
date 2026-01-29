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
    ListNode* func(ListNode* head, unordered_set<int>& u_set){
        if(!head) return head;
        if(u_set.find(head->val)!=u_set.end())
            return func(head->next, u_set);
        head->next = func(head->next, u_set);
        return head;
    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> u_set;
        int n = nums.size();
        for(int i = 0; i < n; i++)
            u_set.insert(nums[i]);
        return func(head, u_set);
    }
};
