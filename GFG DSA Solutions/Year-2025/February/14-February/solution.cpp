/*
class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
    public:
      void func(Node* root, vector<int>& vec, vector<Node*>& nodes){
          if(!root) return ;
          func(root->left, vec, nodes);
          vec.push_back(root->data);
          nodes.push_back(root);
          func(root->right, vec, nodes);
          return ;
      }
      
      void correctBST(Node* root) {
          // add code here.
          vector<int> vec;
          vector<Node*> nodes;
          func(root, vec, nodes);
          int idx1 = -1, idx2 = -1, n = vec.size()-1;
          for(int i = 0; i < n; i++){
              if(vec[i]>vec[i+1]){
                  if(idx1==-1)
                      idx1 = i, idx2 = i+1;
                  else
                      idx2 = i+1;
              }
          }
          nodes[idx1]->data = vec[idx2], nodes[idx2]->data = vec[idx1];
          return ;
      }
  };
  