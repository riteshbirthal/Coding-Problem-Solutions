class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int n = arr.size(), res = 0, left = 0, right = 0;
        unordered_map<int, int> dist;
        while(right<n){
            dist[arr[right]] = dist.find(arr[right])==dist.end() ? 1 : dist[arr[right]] + 1;
            while(dist.size()>k){
                dist[arr[left]]==1 ? dist.erase(arr[left]) : dist[arr[left]]--;
                left += 1;
            }
            if(dist.size()<=k)
                res += (right - left + 1);
            right += 1;
        }
        return res;
    }
};
