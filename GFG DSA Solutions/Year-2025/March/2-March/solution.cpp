class Solution {
    public:
      vector<int> maxOfSubarrays(vector<int>& arr, int k) {
          // code here
          map<int, int> mp;
          vector<int> res;
          int n = arr.size();
          for(int i = 0; i < n; i++){
              if(i<k-1){
                  mp[arr[i]]++;
                  continue;
              }
              mp[arr[i]]++;
              res.push_back(mp.rbegin()->first);
              mp[arr[i-k+1]]==1 ? mp.erase(arr[i-k+1]) : mp[arr[i-k+1]]--;
          }
          return res;
      }
};