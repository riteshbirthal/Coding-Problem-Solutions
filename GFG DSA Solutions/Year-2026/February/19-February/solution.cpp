class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        // code here
        unordered_set<int> u(arr.begin(), arr.end());
        vector<int> res;
        for(int i = low; i <= high; i++)
            if(u.find(i)==u.end())
                res.push_back(i);
        return res;
    }
};
