class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        sort(arr.begin(), arr.end());
        int n = arr.size(), right = 1, m;
        vector<vector<int>> vec;
        vec.push_back(arr[0]);
        while(right < n){
            m = vec.size();
            if(arr[right][0]<=vec[m-1][1]){
                vec[m-1][1] = max(vec[m-1][1], arr[right][1]);
            }else{
                vec.push_back(arr[right]);
            }
            right++;
        }
        return vec;
    }
};