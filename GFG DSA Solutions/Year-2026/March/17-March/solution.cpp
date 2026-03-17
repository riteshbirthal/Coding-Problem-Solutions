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
    map<Node*, Node*> parent;
    set<Node*> isVisited;
  public:
  
    void getAllParent(Node* node, Node* par){
        if(!node)
            return ;
        parent[node] = par;
        getAllParent(node->left, node);
        getAllParent(node->right, node);
        return ;
    }
  
    Node* getTargetNode(Node* root, int target){
        if(!root)
            return root;
        if(root->data==target)
            return root;
        Node* left = getTargetNode(root->left, target);
        Node* right = getTargetNode(root->right, target);
        return left ? left : right;
    }
  
    int minTime(Node* root, int target) {
        // code here
        Node* targetNode = getTargetNode(root, target), *node;
        getAllParent(root, NULL);
        int res = -1;
        queue<Node*> q;
        q.push(targetNode);
        isVisited.insert(targetNode);
        while(!q.empty()){
            int k = q.size();
            while(k--){
                node = q.front(), q.pop();
                if(node->left && isVisited.find(node->left)==isVisited.end())
                    q.push(node->left), isVisited.insert(node->left);
                if(node->right && isVisited.find(node->right)==isVisited.end())
                    q.push(node->right), isVisited.insert(node->right);
                if(parent[node] && isVisited.find(parent[node])==isVisited.end())
                    q.push(parent[node]), isVisited.insert(parent[node]);
            }
            res++;
        }
        return res;
    }
};
