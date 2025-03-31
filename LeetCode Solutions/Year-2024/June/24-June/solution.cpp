class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, count = 0;
        vector<int> vec(n, 0);
        for(int i = 0; i < n-k; i++){
            if(i<k && ((nums[i] && ans%2) || (!nums[i] && ans%2==0)))
                ans++;
            else if(i>=k && ((nums[i] && (ans-vec[i-k])%2) || (!nums[i] && (ans-vec[i-k])%2==0)))
                ans++;
            vec[i] = ans;
        }
        for(int i = n-k; i < n; i++){
            if(i<k)
                count += (nums[i] && ans%2) || (!nums[i] && ans%2==0);
            else if(i>=k)
                count += (nums[i] && (ans-vec[i-k])%2) || (!nums[i] && (ans-vec[i-k])%2==0);
        }
        if(count==0) return ans;
        if(count==k) return ans+1;
        return -1;
    }
};