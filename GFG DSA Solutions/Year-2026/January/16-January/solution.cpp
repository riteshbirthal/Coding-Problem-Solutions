class Solution {
  public:
    int minMen(vector<int>& arr) {
        // code here
        vector<pair<int, int>> vec;
        int n = arr.size();
        for(int i = 0; i < n; i++)
            if(arr[i]!=-1)
                vec.push_back({i-arr[i], i+arr[i]});
        if(vec.size()==0)
            return -1;
        sort(vec.begin(), vec.end());
        int idx = 0, res = 0, mx_idx, day = 0, m = vec.size();
        if(vec[0].first>0)
            return -1;
        while(idx<m && day<n && vec[idx].first<=day){
            mx_idx = idx;
            while(idx<m && vec[idx].first<=day){
                if(vec[mx_idx].second<=vec[idx].second)
                    mx_idx = idx;
                idx++;
            }
            res++;
            idx = mx_idx+1;
            day = vec[mx_idx].second + 1;
        }
        if(day<n)
            return -1;
        return res;
    }
};
