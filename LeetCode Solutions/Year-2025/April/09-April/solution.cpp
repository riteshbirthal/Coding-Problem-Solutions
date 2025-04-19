class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> st(nums.begin(), nums.end());
        if(*st.begin()<k) 
            return -1;
        int n = st.size(), res = n;
        for(auto x = st.begin(); x != st.end() && *x==k; x++)
            res--;
        return res;
    }
};
