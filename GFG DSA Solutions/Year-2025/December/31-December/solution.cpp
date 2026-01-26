
/*
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
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        // Your code here
        Node* curr = head;
        vector<int> vec;
        while(curr)
            vec.push_back(curr->data), curr = curr->next;
        int left = 0, right = vec.size()-1;
        while(left<right){
            if(vec[left]!=vec[right])   
                return false;
            left++, right--;
        }
        return true;
    }
};


