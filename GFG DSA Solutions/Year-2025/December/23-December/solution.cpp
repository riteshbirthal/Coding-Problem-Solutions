class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        vector<int> res;
        int n = arr.size(), count;
        sort(arr.begin(), arr.end());
        for(auto const& q : queries){
            count = upper_bound(arr.begin(), arr.end(), q[1]) - lower_bound(arr.begin(), arr.end(), q[0]);
            res.push_back(max(0, count));
        }
        return res;
    }
};
