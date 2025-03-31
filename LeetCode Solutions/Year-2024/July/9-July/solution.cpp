class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size(), prev = 0;
        double ans = 0;
        for(int i = 0; i < n; i++){
            ans += max(0, prev - customers[i][0]) + customers[i][1];
            prev = max(prev, customers[i][0]) + customers[i][1];
        }
        return ans/n;
    }
};