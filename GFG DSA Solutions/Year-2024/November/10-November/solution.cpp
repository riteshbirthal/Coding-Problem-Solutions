class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        set<int> st;
        for(auto x : a)
            st.insert(x);
        for(auto x : b)
            st.insert(x);
        vector<int> v;
        for(auto x = st.begin(); x != st.end(); x++)
            v.push_back(*x);
        return v;
    }
};