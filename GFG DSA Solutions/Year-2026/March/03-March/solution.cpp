class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int left = 0, right = 0, n = arr.size(), res = 0;
        unordered_map<int, int> dist;
        while(right<n){
            while(left < right && dist.size()>2){
                dist[arr[left]]==1 ? dist.erase(arr[left]) : dist[arr[left]]--;
                left += 1;
            }
            dist[arr[right]] = dist.find(arr[right])==dist.end() ? 1 : dist[arr[right]] + 1;
            right += 1;
            if(dist.size()<=2)
                res = max(res, right - left);
        }
        return res;
    }
};
