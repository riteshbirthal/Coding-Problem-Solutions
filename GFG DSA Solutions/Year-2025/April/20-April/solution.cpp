//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

struct Node{
    bool isEnd;
    vector<Node*> vec;
    Node(){
        isEnd = false;
        vec = vector<Node*>(2, NULL);
    }
    Node(bool iE){
        isEnd = iE;
        vec = vector<Node*>(2, NULL);
    }
    Node(bool iE, vector<Node*> v){
        isEnd = iE;
        vec = v;
    }
};

class Trie {
  public:
    Node* root;
    Trie() {
        // implement Trie
        root = new Node(false);
    }

    bool insert(int num) {
        // insert word into Trie
        Node* temp = root;
        for(int i = 31; i >= 0; i--){
            if(!temp->vec[(num & (1<<i)) / (1<<i)])
                temp->vec[(num & (1<<i)) / (1<<i)] = new Node(false);
            temp = temp->vec[(num & (1<<i)) / (1<<i)];
        }
        if(temp->isEnd)
            return true;
        temp->isEnd = true;
        return false;
    }
};

// User function Template for C++
class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        // code here
        int res = 0;
        Trie* tr = new Trie();
        
        for(int x : arr)
            if(tr->insert(x))
                res = x;
        return res;
    }
};


//{ Driver Code Starts.

int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        int result = ob.findDuplicate(arr);

        cout << (result) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends