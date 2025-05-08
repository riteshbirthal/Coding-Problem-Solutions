//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends


// User function Template for C++

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/

class Solution {
  public:
    set<int> getPrimes(int limit){
        vector<int> primes(limit, 1);
        primes[0] = primes[1] = 0;
        for(int i = 0; i < limit; i++){
            if(primes[i]==0)
                continue;
            for(int j = 2; j*i < limit; j++){
                primes[i*j] = 0;
            }
        }
        set<int> res;
        for(int i = 0; i < limit; i++){
            if(primes[i]==0)
                continue;
            res.insert(i);
        }
        return res;
    }

    Node *primeList(Node *head) {
        // code here
        set<int> primes = getPrimes(1e4+10);
        primes.insert(-2);
        Node* curr = head;
        while(curr){
            if(primes.find(curr->val)==primes.end()){
                auto itr = primes.lower_bound(curr->val);
                int upper = *itr;
                itr--;
                int lower = *itr;
                if(curr->val-lower <= upper - curr->val){
                    curr->val = lower;
                }else{
                    curr->val = upper;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};




//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.primeList(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends