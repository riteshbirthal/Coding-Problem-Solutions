class Solution {
public:
    int getMaxProduct(vector<int>& nums1, vector<int>& nums2, int n, int m, vector<vector<int>>& dp){
        if(n<0 || m<0)
            return 0;
        if(dp[n][m]!=INT_MIN)
            return dp[n][m];
        int res = max(getMaxProduct(nums1, nums2, n-1, m, dp), getMaxProduct(nums1, nums2, n, m-1, dp));
        res = max(res, nums1[n]*nums2[m] + getMaxProduct(nums1, nums2, n-1, m-1, dp));
        return dp[n][m] = res;
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MIN));
        bool sign1 = nums1[0]!=0, sign2 = nums2[0]!=0;
        for(int i = 1; i < n && sign1; i++)
            sign1 = sign1 && (nums1[i-1]*nums1[i] > 0);
        for(int i = 1; i < m && sign2; i++)
            sign2 = sign2 && (nums2[i-1]*nums2[i] > 0);
        if(sign1 && sign2 && nums1[0]*nums2[0]<0){
            sort(nums1.begin(), nums1.end());
            sort(nums2.begin(), nums2.end());
            return nums1[0] < 0 ? nums1[n-1]*nums2[0] : nums1[0]*nums2[m-1];
        }
        return getMaxProduct(nums1, nums2, n-1, m-1, dp);
    }
};
