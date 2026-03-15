
/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        // Your code here
        vector<vector<int>> res;
        map<int, vector<int>> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        pair<Node*, int> pr;
        while(!q.empty()){
            int k = q.size();
            while(k--){
                pr = q.front(), q.pop();
                mp[pr.second].push_back(pr.first->data);
                if(pr.first->left){
                    q.push({pr.first->left, pr.second-1});
                }
                if(pr.first->right){
                    q.push({pr.first->right, pr.second+1});
                }
            }
        }
        for(auto x = mp.begin(); x != mp.end(); x++)
            res.push_back(x->second);
        return res;
    }
};


