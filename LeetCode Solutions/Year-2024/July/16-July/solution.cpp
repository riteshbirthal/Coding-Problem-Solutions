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
    void func(TreeNode* root, unordered_map<int, int>& parent, int par){
        if(!root) return ;
        parent[root->val] = par;
        func(root->left, parent, root->val);
        func(root->right, parent, root->val);
        return ;
    }

    TreeNode* find_node(TreeNode* root, int lcs){
        if(!root) return NULL;
        if(root->val==lcs) return root;
        TreeNode* left = find_node(root->left, lcs), *right = find_node(root->right, lcs);
        if(left) return left;
        return right;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        unordered_map<int, int> parent;
        func(root, parent, -1);
        vector<int> left, right;
        int lcs, l_p = startValue, r_p = destValue;
        while(l_p!=-1 || r_p!=-1){
            if(l_p!=-1){
                left.push_back(l_p);
                l_p = parent[l_p];
            }
            if(r_p!=-1){
                right.push_back(r_p);
                r_p = parent[r_p];
            }
        }
        while(left.size() && right.size() && left[left.size()-1]==right[right.size()-1]){
            lcs = left[left.size()-1];
            left.pop_back();
            right.pop_back();
        }
        string ans = "";
        while(startValue!=lcs){
            ans += "U";
            startValue = parent[startValue];
        }
        TreeNode* lcs_node = find_node(root, lcs);
        while(destValue!=lcs_node->val){
            if(lcs_node->left && right[right.size()-1]==lcs_node->left->val){
                ans += "L";
                lcs_node = lcs_node->left;
            }else{
                ans += "R";
                lcs_node = lcs_node->right;
            }
            right.pop_back();
        }
        return ans;
    }
};