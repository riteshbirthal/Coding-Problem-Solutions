class Solution {
    public:
        bool check(vector<int>& nums) {
            int n = nums.size();
            vector<int> vec = nums;
            sort(vec.begin(), vec.end());
            for(int idx = 0; idx < n; idx++){
                bool ans = true;
                for(int i = 0; i < n; i++){
                    if(vec[i]!=nums[(idx+i)%n])
                        ans = false;
                }
                if(ans)
                    return true;
            }
            return false;
        }
    };