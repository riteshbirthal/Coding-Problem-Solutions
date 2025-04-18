//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

struct Node{
    bool isEnd;
    vector<Node*> vec;
    Node(bool isEnd){ 
        isEnd = isEnd; 
        vec = vector<Node*>(26, NULL);
    }
    Node(bool isEnd, vector<Node*> v){ 
        isEnd = isEnd; 
        vec = v;
    }
};

// User function template for C++
class Trie {
  public:
    Node* root;
    Trie() {
        // implement Trie
        root = new Node(false);
    }

    void insert(string &word) {
        // insert word into Trie
        Node* temp = root;
        for(char ch : word){
            if(!temp->vec[ch-'a'])
                temp->vec[ch-'a'] = new Node(false);
            temp = temp->vec[ch-'a'];
        }
        temp->isEnd = true;
        return ;
    }

    bool search(string &word) {
        // search word in the Trie
        Node* temp = root;
        for(char ch : word){
            if(!temp->vec[ch-'a'])
                return false;
            temp = temp->vec[ch-'a'];
        }
        return temp->isEnd;
    }

    bool isPrefix(string &word) {
        // search prefix word in the Trie
        Node* temp = root;
        for(char ch : word){
            if(!temp->vec[ch-'a'])
                return false;
            temp = temp->vec[ch-'a'];
        }
        return true;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int q;
        cin >> q;
        cin.ignore();
        vector<bool> ans;
        Trie ob;
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            string s;
            cin >> s;
            cin.ignore();
            if (x == 1) {
                ob.insert(s);
            } else if (x == 2) {
                ans.push_back(ob.search(s));
            } else if (x == 3) {
                ans.push_back(ob.isPrefix(s));
            }
        }
        cout << boolalpha;
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends