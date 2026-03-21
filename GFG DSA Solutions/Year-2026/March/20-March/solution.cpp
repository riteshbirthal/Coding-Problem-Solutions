/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void getPreSuc(Node* root, int key, vector<Node*>& res){
        if(!root) return ;
        if(root->data > key){
            res[1] = root;
            getPreSuc(root->left, key, res);
            return ;
        }else if(root->data < key){
            res[0] = root;
            getPreSuc(root->right, key, res);
            return ;
        }
        getPreSuc(root->left, key, res);
        getPreSuc(root->right, key, res);
        return ;
    }
    
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<Node*> res = {NULL, NULL};
        getPreSuc(root, key, res);
        return res;
    }
};
