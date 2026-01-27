class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
        set<int> nums, rep;
        for(int x : arr){
            nums.find(x)==nums.end() ? nums.insert(x) : rep.insert(x);
        }
        vector<int> ans(rep.begin(), rep.end());
        return ans;
    }
};
