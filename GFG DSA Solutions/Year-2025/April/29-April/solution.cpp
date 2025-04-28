//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends

/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {
        // code here
        Node* zeros = new Node(0), *curr_z = zeros;
        Node* ones = new Node(1), *curr_o = ones;
        Node* twos = new Node(2), *curr_t = twos;
        while(head){
            if(head->data==0){
                curr_z->next = head;
                head = head->next;
                curr_z = curr_z->next;
                curr_z->next = NULL;
            }else if(head->data==1){
                curr_o->next = head;
                head = head->next;
                curr_o = curr_o->next;
                curr_o->next = NULL;
            }else{
                curr_t->next = head;
                head = head->next;
                curr_t = curr_t->next;
                curr_t->next = NULL;
            }
        }
        curr_o->next = twos->next;
        curr_z->next = ones->next;
        return zeros->next;
    }
};



//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        Node* newHead = ob.segregate(head);
        printList(newHead);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends
