/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
    unordered_map<int, int> u;
  public:
    int calculatePaths(Node* root, int k, int currSum){
        if(!root)
            return 0;
        currSum += root->data;
        int res = u.find(currSum-k)==u.end() ? 0 : u[currSum-k];
        u.find(currSum)==u.end() ? u[currSum] = 1 : u[currSum]++;
        res += calculatePaths(root->left, k, currSum);
        res += calculatePaths(root->right, k, currSum);
        u[currSum]==1 ? u.erase(currSum) : u[currSum]--;
        return res;
    }
  
    int countAllPaths(Node *root, int k) {
        // code here
        u[0] = 1;
        return calculatePaths(root, k, 0);
    }
};
