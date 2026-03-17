/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
    int res;
  public:
    int findMinMoves(Node* root){
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return root->data - 1;
        int left, right;
        left = findMinMoves(root->left), right = findMinMoves(root->right);
        res += abs(left) + abs(right);
        return root->data + left + right - 1;
    }
    
    int distCandy(Node* root) {
        // code here
        res = 0;
        findMinMoves(root);
        return res;
    }
};
