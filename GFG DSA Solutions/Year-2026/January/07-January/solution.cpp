class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        unordered_map<int, int> dist;
        vector<int> res;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            dist[arr[i]]++;
            if(i<k-1)
                continue;
            res.push_back(dist.size());
            dist[arr[i-k+1]]==1 ? dist.erase(arr[i-k+1]) : dist[arr[i-k+1]]--;
        }
        return res;
    }
};
