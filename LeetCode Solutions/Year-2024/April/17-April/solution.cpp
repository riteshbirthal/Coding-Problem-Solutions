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
    string compare_strings(string st1, string st2){
        for(int i = 0; i < st1.size(); i++){
            if(st1[i]<st2[i]) return st1;
            else if(st1[i]>st2[i]) return st2;
        }
        if(st1.size()!=st2.size()) return (st1.size()<st2.size()) ? st1 : st2;
        return st1;
    }
    string func(TreeNode* root, string st1, string & comp){
        if(root->left==NULL && root->right==NULL){
            st1 += ('a' + root->val);
            reverse(st1.begin(), st1.end());
            if(comp.size()==0) return comp = st1;
            return comp = compare_strings(st1, comp);
        }
        st1 += ('a' + root->val);
        string ans1 = "", ans2 = "";
        if(root->left) ans1 = func(root->left, st1, comp);
        if(root->right) ans2 = func(root->right, st1, comp);
        if(ans1!="" && ans2!="") return comp = compare_strings(ans1, ans2);
        else if(ans1!="") return comp = ans1;
        return comp = ans2;
    }
    string smallestFromLeaf(TreeNode* root) {
        string comp = "";
        string answer = func(root, "", comp);
        return answer;
    }
};