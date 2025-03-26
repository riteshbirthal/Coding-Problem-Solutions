class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            set<int> st;
            st.insert(0);
            int res = 0, sum = 0;
            for(int x : nums){
                sum += x;
                res = max(res, sum < 0 ? abs(sum - *st.rbegin()) : sum - *st.begin());
                st.insert(sum);
            }
            return res;
        }
    };