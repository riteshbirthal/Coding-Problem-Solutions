class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size(), m = worker.size(), mx = INT_MIN, ans = 0, left, right, mid;
        vector<vector<int>> vec;
        for(int i = 0; i < n; i++){
            vec.push_back({difficulty[i], profit[i]});
        }
        sort(vec.begin(), vec.end());
        for(int i = 0; i < n; i++){
            mx = max(mx, vec[i][1]);
            vec[i][1] = mx;
        }
        for(int i = 0; i < m; i++){
            left = 0, right = n - 1;
            while(left<=right){
                mid = (left + right) / 2;
                if(vec[mid][0] <= worker[i]){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }
            if(mid + 1 < n && vec[mid+1][0]<=worker[i])
                ans += vec[mid+1][1];
            else if(vec[mid][0]<=worker[i])
                ans += vec[mid][1];
            else if(mid && vec[mid-1][0]<=worker[i])
                ans += vec[mid-1][1];
        }
        return ans;
    }
};