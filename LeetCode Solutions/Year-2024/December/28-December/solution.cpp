class Solution {
    public:
        vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
            vector<int> vec, res, t;
            int n = nums.size(), sum = 0, idx, mx = 0;
            for(int i = 0; i < n; i++){
                if(i<k-1){
                    sum += nums[i];
                    continue;
                }
                sum += nums[i];
                vec.push_back(sum);
                sum -= nums[i+1-k];
            }
            vector<vector<int>> v;
            n = vec.size();
            n = nums.size(), idx = n-k, sum = 0;
            for(int i = n-2*k; i >= 0; i--){
                if(vec[i+k]>=vec[idx]){
                    idx = i+k;
                }
                if(vec[i] + vec[idx]>=sum){
                    v.push_back({i, idx});
                    sum = vec[i] + vec[idx];
                    t = {i, idx};
                }else{
                    v.push_back(t);
                }
            }
            reverse(v.begin(), v.end());
            n = v.size();
            for(int i = 0; i < n-k; i++){
                if(vec[i] + vec[v[i+k][0]] + vec[v[i+k][1]] > mx){
                    res = {i, v[i+k][0], v[i+k][1]};
                    mx = vec[i] + vec[v[i+k][0]] + vec[v[i+k][1]];
                }
            }
            return res;
        }
    };