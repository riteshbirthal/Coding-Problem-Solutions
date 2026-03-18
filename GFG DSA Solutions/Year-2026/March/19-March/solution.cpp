/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    // return {max tree size, {isBST, vector<int>{total nodes, minNode, LargestNode}}};
    pair<int, pair<bool, vector<int>>> getLargestBst(Node* root){
        if(!root)
            return {0, {true, vector<int>{0, INT_MAX, INT_MIN}}};
        pair<int, pair<bool, vector<int>>> left, right;
        left = getLargestBst(root->left);
        right = getLargestBst(root->right);
        int maxSize = 1, totalEle = 1, minEle = INT_MAX, maxEle = INT_MIN;
        bool isBST = true;
        vector<int> vec(3);
        // if children are BST
        if(left.second.first && right.second.first){
            if(left.second.second[2] < root->data && root->data < right.second.second[1]){
                maxSize = 1 + left.second.second[0] + right.second.second[0];
                totalEle = maxSize;
                minEle = root->left ? left.second.second[1] : root->data;
                maxEle = root->right ? right.second.second[2] : root->data;
                vec = vector<int>{totalEle, minEle, maxEle};
            }else{
                maxSize = max(1, max(left.first, right.first));
                isBST = false;
            }
        }else{
            maxSize = max(1, max(left.first, right.first));
            isBST = false;
        }
        return {maxSize, {isBST, vec}};
    }
    
    int largestBst(Node *root) {
        // Your code here
        int res = getLargestBst(root).first;
        return res;
    }
};
