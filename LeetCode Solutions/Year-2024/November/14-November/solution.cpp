class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 0, right = 1e6, mid = INT_MAX, m = quantities.size(), count;
        while(left <= right){
            mid = (left + right) / 2;
            count = 0;
            for(int i = 0; i < m && mid; i++){
                count += quantities[i]/mid + (quantities[i]%mid ? 1 : 0);
            }
            if(count<=n && mid) right = mid-1;
            else left = mid+1;
        }
        if(count<=n) return mid;
        return left;
    }
};