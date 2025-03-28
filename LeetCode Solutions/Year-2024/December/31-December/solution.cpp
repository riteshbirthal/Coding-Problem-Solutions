class Solution {
    public:
        int func(vector<int>& days, int n, vector<int>& costs, vector<int>& dp){
            if(n>=days.size())
                return 0;
            if(dp[n]!=-1)
                return dp[n];
            int a, b, c, idx, m = days.size();
            a = costs[0] + func(days, n+1, costs, dp);
            idx = n+1;
            while(idx<m && days[idx]-days[n]<7){
                idx++;
            }
            b = costs[1] + func(days, idx, costs, dp);
            idx = n+1;
            while(idx<m && days[idx]-days[n]<30){
                idx++;
            }
            c = costs[2] + func(days, idx, costs, dp);
            return dp[n] = min(a, min(b, c));
        }
        int mincostTickets(vector<int>& days, vector<int>& costs) {
            int n = days.size();
            vector<int> dp(n+1, -1);
            return func(days, 0, costs, dp);
        }
    };