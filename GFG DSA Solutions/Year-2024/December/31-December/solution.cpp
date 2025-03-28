class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
         set<int> st(arr.begin(), arr.end());
        int res = 1, ele = INT_MIN, count = 1;
        for(auto x = st.begin(); x != st.end(); x++){
            if(ele==*x-1){
                count++;
            }else{
                res = max(res, count);
                count = 1;
            }
            ele = *x;
        }
        res = max(res, count);
        return res;
    }
};