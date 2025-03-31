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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> vec;
        ListNode* prev = head, *curr = head->next, *next;
        if(curr)
            next = curr->next;
        int idx = 1;
        while(prev && curr && next){
            if(curr->val > prev->val && curr->val > next->val){
                vec.push_back(idx);
            }else if(curr->val < prev->val && curr->val < next->val){
                vec.push_back(idx);
            }
            idx++;
            prev = curr, curr = next, next = next->next;
        }
        if(vec.size()<2)
            return {-1, -1};
        int mn = INT_MAX, mx = vec[vec.size()-1] - vec[0];
        for(int i = 1; i < vec.size(); i++)
            mn = min(mn, vec[i] - vec[i-1]);
        return {mn, mx};
    }
};