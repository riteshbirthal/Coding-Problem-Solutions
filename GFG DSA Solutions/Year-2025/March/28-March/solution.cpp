class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        int n = start.size(), res = 1, left, right, mid, mx = 0;
        vector<vector<int>> acts, vec(n + 1, {1, 1});
        for(int i = 0; i < n; i++)
            acts.push_back({start[i], finish[i]});
        sort(acts.begin(), acts.end());
        for(int i = n-1; i >= 0; i--){
            left = i+1, right = n-1, mx = 0;
            while(left<=right){
                if(acts[i][1]<acts[mid][0]){
                    mx = max(mx, vec[mid][1]);
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
                mid = (left + right) / 2;
            }
            vec[i] = {1 + mx, max(1 + mx, vec[i+1][1])};
            res = max(res, vec[i][0]);
        }
        return res;
    }
};
