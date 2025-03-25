class Solution {
    public:
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            int n = nums.size(), m = queries.size(), preSum = 0, res = m+1, left = 0, right = m, mid, flag;
            while(left<=right){
                mid = (left + right) / 2;
                vector<int> vec(n, 0);
                for(int i = 0; i < mid; i++){
                    vec[queries[i][0]] += queries[i][2];
                    if(queries[i][1]+1<n)
                        vec[queries[i][1]+1] -= queries[i][2];
                }
                preSum = 0, flag = 1;
                for(int i = 0; i < n; i++){
                    preSum += vec[i];
                    if(nums[i]>preSum)
                        flag = 0;
                }
                if(flag){
                    res = mid;
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
            return res==m+1 ? -1 : res;
        }
    };