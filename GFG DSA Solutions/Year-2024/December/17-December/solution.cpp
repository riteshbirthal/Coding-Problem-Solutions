// User function Template for C++

class Solution {
  public:

    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin(), stalls.end());
        int n = stalls.size(), left = 0, right = stalls[n-1]-stalls[0], mid, ans = INT_MIN, idx, count;
        while(left<=right){
            mid = (left + right) / 2;
            idx = 0, count = k-1;
            for(int i = 1; i < n && count; i++){
                if(stalls[i]-stalls[idx]>=mid){
                    count--;
                    idx = i;
                }
            }
            if(count){
                right = mid-1;
            }else{
                ans = max(ans, mid);
                left = mid + 1;
            }
        }
        return ans;
    }
};