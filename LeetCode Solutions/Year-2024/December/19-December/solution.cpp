class Solution {
    public:
        int maxChunksToSorted(vector<int>& arr) {
            int ans = 0, n = arr.size(), mx, mn, idx;
            vector<int> left(n, INT_MIN), right(n, INT_MAX), v = arr;
            sort(v.begin(), v.end());
            if(v==arr)
                return n;
            for(int i = 1; i < n; i++){
                left[i] = max(arr[i-1], left[i-1]);
                right[n-i-1] = min(arr[n-i], right[n-i]);
            }
            for(int i = 0; i < n; i++){
                mx = arr[i], mn = arr[i], idx = i;
                while(i<n && (mx>right[i] || mn<left[idx])){
                    mx = max(mx, arr[i]);
                    mn = min(mn, arr[i]);
                    i++;
                }
                ans++;
            }
            return ans;
        }
    };