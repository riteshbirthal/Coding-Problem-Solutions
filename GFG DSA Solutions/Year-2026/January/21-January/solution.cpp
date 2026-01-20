class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // write code here
        stack<pair<int, int>> st;
        st.push({INT_MAX, -1});
        int n = arr.size();
        vector<int> res;
        for(int i = 0; i < n; i++){
            while(st.top().first<=arr[i])
                st.pop();
            res.push_back(i-st.top().second);
            st.push({arr[i], i});
        }
        return res;
    }
};
