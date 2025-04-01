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
    ListNode* removeNodes(ListNode* head) {
        ListNode* temp = head;
        vector<int> vec;
        while(temp){
            vec.push_back(temp->val);
            temp = temp->next;
        }
        int ele = -1;
        vector<int> vec2;
        for(int i = vec.size()-1; i >=0; i--){
            if(vec[i]>=ele){
                vec2.push_back(vec[i]);
                ele = vec[i];
            }
        }
        reverse(vec2.begin(), vec2.end());
        ele = 0;
        temp = new ListNode(-1, head);
        ListNode* temp2 = temp;
        while(temp && ele<vec2.size()){
            if(temp->next->val==vec2[ele]){
                temp = temp->next;
                ele++;
            }else{
                if(!temp->next) break;
                temp->next = temp->next->next;
            }
        }
        return temp2->next;
    }
};