//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

struct Node{
    bool isEnd;
    vector<Node*> vec;
    Node(bool isEnd){ 
        isEnd = isEnd; 
        vec = vector<Node*>(2, NULL);
    }
    Node(bool isEnd, vector<Node*> v){ 
        isEnd = isEnd; 
        vec = v;
    }
};
// User function Template for C++

class Trie {
  public:
    Node* root;
    Trie() {
        // implement Trie
        root = new Node(false);
    }

    void insert(int num) {
        // insert word into Trie
        Node* temp = root;
        for(int i = 31; i >= 0; i--){
            if(!temp->vec[(num & (1<<i)) / (1<<i)])
                temp->vec[(num & (1<<i)) / (1<<i)] = new Node(false);
            temp = temp->vec[(num & (1<<i)) / (1<<i)];
        }
        temp->isEnd = true;
        return ;
    }

    int getMax(int num) {
        // search word in the Trie
        Node* temp = root;
        int res = 0;
        for(int i = 31; i >= 0; i--){
            if((num & (1<<i)) / (1<<i)){
                if(temp->vec[0]){
                    res += (1<<i);
                    temp = temp->vec[0];
                }else{
                    temp = temp->vec[1];
                }
            }else{
                if(temp->vec[1]){
                    res += (1<<i);
                    temp = temp->vec[1];
                }else{
                    temp = temp->vec[0];
                }
            }
                
        }
        return res;
    }
};

class Solution {
  public:
    int maxXor(vector<int> &arr) {
        // code here
        int res = 0;
        Trie* tr = new Trie();
        
        for(int x : arr)
            tr->insert(x);
            
        for(int x : arr)
            res = max(res, tr->getMax(x));
            
        return res;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.maxXor(arr) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends