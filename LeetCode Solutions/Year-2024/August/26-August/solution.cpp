/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void func(Node* root, vector<int>& ans){
        if(!root) 
            return ;
        for(int i = 0; i < root->children.size(); i++){
            func(root->children[i], ans);
        }
        ans.push_back(root->val);
        return ;
    }
    vector<int> postorder(Node* root) {
        vector<int> ans;
        func(root, ans);
        return ans;
    }
};