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
        int calculate_swaps(vector<int>& arr){
            vector<int> temp = arr;
            sort(temp.begin(), temp.end());
            unordered_map<int, int> mp;
            for(int i = 0; i < arr.size(); i++){
                mp[arr[i]] = i;
            }
            int count = 0;
            for(int i = 0; i < arr.size(); i++){
               if(arr[i] != temp[i]){
                  int ind = mp[temp[i]];
                  mp[arr[i]] = ind;
                  swap(arr[i], arr[ind]);
                  count++;
               }
            }
            return count;
        }

        int minimumOperations(TreeNode* root) {
            queue<TreeNode*> q;
            q.push(root);
            int swaps = 0;
            while(!q.empty()){
                 int size = q.size();
                 vector<int> temp;
                 while(size--){
                    TreeNode* node = q.front(); q.pop();
                    temp.push_back(node->val);
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                 }
                 swaps += calculate_swaps(temp);
            }
            return swaps;
        }
    };