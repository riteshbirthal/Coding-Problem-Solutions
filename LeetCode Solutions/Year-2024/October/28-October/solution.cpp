class Solution {
    public:
        int longestSquareStreak(vector<int>& nums) {
            int ans = 0, count;
            long long ele;
            unordered_map<long long, int> u;
            for(auto n : nums)
                u[n]++;
            for(auto x = u.begin(); x != u.end(); x++){
                count = 1, ele = x->first;
                while(ele<1e7 && u.find(ele)!=u.end() && u.find(ele*ele)!=u.end()){
                    ele *= ele;
                    count++;
                }
                ans = max(ans, count);
            }
            if(ans<2) return -1;
            return ans;
        }
    };