class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        vector<int> vec(n, events[n-1][2]);
        for(int i = n-2; i >= 0; i--)
            vec[i] = max(events[i][2], vec[i+1]);
        int left, right, mid, ans = vec[0], idx;
        for(int i = 0; i < n; i++){
            left = i+1, right = n-1, idx = n-1;
            if(events[i][1]>=events[n-1][0])
                continue;
            while(left<=right){
                mid = (left + right) / 2;
                if(events[mid][0]>events[i][1]){
                    idx = mid;
                    right = mid-1;
                }else{
                    left = mid+1;
                }
            }
            ans = max(ans, events[i][2]+vec[idx]);
        }
        return ans;
    }
};
