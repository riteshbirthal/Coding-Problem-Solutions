class Solution {
    public:
        vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
            vector<bool> ans;
            int n = nums.size(), left = 0;
            vector<int> starts, ends;
            nums[0] = nums[0]%2;
            for(int i = 1; i < n; i++){
                nums[i] = nums[i]%2;
                if(nums[i]==nums[i-1]){
                    starts.push_back(left);
                    ends.push_back(i-1);
                    left = i;
                }
            }
            starts.push_back(left);
            ends.push_back(n-1);
            int idx;
            for(auto q : queries){
                idx = lower_bound(starts.begin(), starts.end(), q[0]) - starts.begin();
                cout << idx << endl;
                if(idx==starts.size() || starts[idx]!=q[0])
                    idx--;
                starts[idx]<=q[0] && ends[idx]>=q[1] ? ans.push_back(true) : ans.push_back(false);
            }
            return ans;
        }
    };