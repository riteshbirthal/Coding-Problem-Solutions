
// User function Template for C++
class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        int n = arr.size(), res = 0, sum = 0;
        unordered_map<int, int> u;
        u[sum] = -1;
        for(int i = 0; i < n; i++){
            sum += arr[i]>k ? 1 : -1;
            u.find(sum)==u.end() ? u[sum] = i : u[sum] = u[sum];
        }
        
        if(u.find(-n) != u.end())
            return 0;
      
    	u[-n] = n;
        for(int i = -n + 1; i <= n; i++) {
            if(u.find(i) == u.end())
                u[i] = u[i-1];
            else
                u[i] = min(u[i], u[i-1]);
        }
        
        sum = 0;
        for(int i = 0; i < n; i++) {
        	sum += (arr[i] > k ? 1 : -1);
            if(sum > 0)
                res = i + 1;
            else
            	res = max(res, i - u[sum - 1]);
        }
        return res;
    }
};

