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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool func(ListNode* head, ListNode* curr_head, TreeNode* root, map<pair<ListNode*, TreeNode*>, bool> & mp){
        if(curr_head==NULL) return true;
        if(root==NULL) return false;
        if(mp.find({curr_head, root})!=mp.end()) return mp[{curr_head, root}];
        if(func(head, head, root->left, mp) || func(head, head, root->right, mp))
            return mp[{curr_head, root}] = true;
        if(root->val==curr_head->val){
            if(func(head, curr_head->next, root->left, mp))
                return mp[{curr_head, root}] = true;
            return mp[{curr_head, root}] = func(head, curr_head->next, root->right, mp);
        }
        return mp[{curr_head, root}] = false;
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        map<pair<ListNode*, TreeNode*>, bool> mp;
        return func(head, head, root, mp);
    }
};