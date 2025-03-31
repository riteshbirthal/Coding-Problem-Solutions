class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_set<long long> st;
        for(long long i = 0; i <= sqrt(c) + 1; i++)
            st.insert(i*i);
        for(auto x = st.begin(); x != st.end(); x++)
            if(st.find(c - *x)!=st.end()) return true;
        return false;
    }
};