class Solution {
  public:
    static bool sort_func(vector<int>& a, vector<int>& b){
        if(a[1]!=b[1]) return a[1]<b[1];
        return a[0]>=b[0];
    }
    int minRemoval(vector<vector<int>> &intervals) {
        // code here
        sort(intervals.begin(), intervals.end(), sort_func);
        int n = intervals.size(), count = 0, mx = INT_MIN;
        for(int i = 0; i < n; i++){
            if(intervals[i][0]>=mx){
                count++;
                mx = intervals[i][1];
            }
        }
        return n - count;
    }
};
