class Solution {
    public:
        vector<int> finalPrices(vector<int>& prices) {
            int n = prices.size();
            vector<int> vec(n, 0);
            stack<int> st;
            st.push(0);
            for(int i = n-1; i >= 0; i--){
                while(st.top()>prices[i])
                    st.pop();
                vec[i] = prices[i] - st.top();
                st.push(prices[i]);
            }
            return vec;
        }
    };