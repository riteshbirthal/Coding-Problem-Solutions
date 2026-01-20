class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> vec(nums[n-1]+1);
        for(int i = 2; i < nums[n-1]+1; i++){
            for(int j = 2; j*i < nums[n-1]+1; j++){
                vec[i*j].push_back(i);
            }
        }
        int res = 0;
        for(int x : nums){
            if(vec[x].size()==2){
                res += vec[x][0] + vec[x][1] + x + 1;
            }
        }
        return res;
    }
};
