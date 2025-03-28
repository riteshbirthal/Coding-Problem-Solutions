class Solution {
    public:
        int maxCount(vector<int>& banned, int n, int maxSum) {
            unordered_set<int> st(banned.begin(), banned.end());
            int sum = 0, count = 0;
            for(int i = 1; i <= n && sum+i<=maxSum; i++){
                if(st.find(i)==st.end())
                    count++, sum += i;
            }
            return count;
        }
    };