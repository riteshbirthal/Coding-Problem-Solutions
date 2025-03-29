// User function Template for C++

class Solution {
  public:
    int minIncrements(vector<int>& arr) {
        // Code here
        int n = arr.size(), ans = 0;
        sort(arr.begin(), arr.end());
        for(int i = 1; i < n; i++){
            ans += max(0, arr[i-1]+1-arr[i]);
            arr[i] = max(arr[i], arr[i-1]+1);
        }
        return ans;
    }
};