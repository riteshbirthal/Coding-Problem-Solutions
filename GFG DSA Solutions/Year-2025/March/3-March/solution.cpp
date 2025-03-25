class Solution {
    public:
      vector<int> longestSubarray(vector<int>& arr, int x) {
          // code here
          int idx = 0, maxLen = 1, count = 0, n = arr.size();
          map<int, int> mp;
          for(int i = 0; i < n; i++){
              while(mp.size() && (abs(mp.begin()->first-arr[i])>x || abs(mp.rbegin()->first-arr[i])>x)){
                  mp[arr[i-count]]==1 ? mp.erase(arr[i-count]) : mp[arr[i-count]]--;
                  count--;
              }
              mp.find(arr[i])==mp.end() ? mp[arr[i]] = 1 : mp[arr[i]]++;
              count++;
              if(count>maxLen){
                  maxLen = count;
                  idx = i+1-count;
              }
          }
          vector<int> res(arr.begin()+idx, arr.begin()+idx+maxLen);
          return res;
      }
};