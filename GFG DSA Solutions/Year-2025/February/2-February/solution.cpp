/* A binary tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
    public:
      vector<vector<int>> levelOrder(Node *root) {
          // Your code here
          queue<Node*> q;
          q.push(root);
          unordered_set<Node*> u;
          u.insert(root);
          vector<vector<int>> res;
          int k;
          while(!q.empty()){
              k = q.size();
              vector<int> vec;
              while(k--){
                  root = q.front(); q.pop();
                  vec.push_back(root->data);
                  if(root->left && u.find(root->left)==u.end()){
                      u.insert(root->left);
                      q.push(root->left);
                  }
                  if(root->right && u.find(root->right)==u.end()){
                      u.insert(root->right);
                      q.push(root->right);
                  }
              }
              res.push_back(vec);
          }
          return res;
      }
  };