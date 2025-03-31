class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> ans;
        int m = rolls.size(), sum = 0;
        for(auto x : rolls)
            sum += x;
        // total sum of n+m observations that should be 
        sum = mean * (n + m) - sum;
        if(sum<n || sum>6*n)
            return ans;
        for(int i = 0; i < sum%n; i++)
            ans.push_back(sum/n + 1);
        for(int i = 0; i < n-sum%n; i++)
            ans.push_back(sum/n);
        return ans;
    }
};