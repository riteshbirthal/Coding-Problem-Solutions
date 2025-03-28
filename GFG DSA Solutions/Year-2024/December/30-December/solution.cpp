// User function template in C++

class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_set<int> u;
        for(int x : a)
            u.insert(x);
        for(int x : b)
            u.insert(x);
        return u.size();
    }
};