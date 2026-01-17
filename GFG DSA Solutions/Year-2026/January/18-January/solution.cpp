class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        // code here
        unordered_map<int, int> freq;
        for(int x : arr)
            freq[x] = freq.find(x)==freq.end() ? 1 : freq[x] + 1;
        stack<pair<int, int>> stk;
        vector<int> res;
        for(int i = arr.size()-1; i >= 0; i--){
            while(stk.size() && stk.top().second<=freq[arr[i]])
                stk.pop();
            res.push_back(stk.size() ? stk.top().first : -1);
            stk.push({arr[i], freq[arr[i]]});
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
