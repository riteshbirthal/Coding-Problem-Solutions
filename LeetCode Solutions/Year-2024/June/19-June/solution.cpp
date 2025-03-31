class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size(), left = 0, right, mid, count_k, count_m, ans = INT_MIN;
        if((long long)m*k > n) return -1;
        for(int i = 0; i < n; i++) ans = max(ans, bloomDay[i]);
        right = ans;
        while(left<=right){
            mid = (left + right) / 2;
            count_k = 0, count_m = m;
            for(int i = 0; i < n; i++){
                if(bloomDay[i]<=mid){
                    count_k++;
                }else{
                    count_k = 0;
                }
                if(count_k==k){
                    count_k = 0;
                    count_m--;
                }
            }
            if(count_m<=0){
                ans = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return ans;
    }
};