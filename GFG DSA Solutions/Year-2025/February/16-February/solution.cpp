/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution {
    public:
      // Function to serialize a tree and return a list containing nodes of tree.
      vector<int> serialize(Node *root) {
          // Your code here
          vector<int> res;
          queue<Node*> q;
          q.push(root);
          int k;
          while(!q.empty()){
              k = q.size();
              for(int i = 0; i < k; i++){
                  root = q.front(), q.pop();
                  if(!root){
                      res.push_back(0);
                  }else{
                      res.push_back(root->data);
                      q.push(root->left);
                      q.push(root->right);
                  }
              }
          }
          return res;
      }
  
      // Function to deserialize a list and construct the tree.
      Node *deSerialize(vector<int> &arr) {
          // Your code here
          int n = arr.size(), idx = 1, k = 1, prevK = 1;
          Node* root = new Node(arr[0]), *node;
          queue<Node*> q;
          q.push(root);
          while(!q.empty()){
              k = q.size();
              for(int i = 0; i < k && idx < n; i++){
                  node = q.front(), q.pop();
                  node->left = arr[idx] ? new Node(arr[idx]) : NULL;
                  if(node->left)
                      q.push(node->left);
                  idx++;
                  node->right = arr[idx] ? new Node(arr[idx]) : NULL;
                  if(node->right)
                      q.push(node->right);
                  idx++;
              }
          }
          return root;
      }
  };