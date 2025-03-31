class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = 0, n = nums.size(), l, r;
        vector<int> indices;
        for(int i = 0; i < n; i++){
            if(nums[i]%2)
                indices.push_back(i);
        }
        for(int j = k-1; j < indices.size(); j++){
            l = indices[j-k+1], r = indices[j];
            if(j-k+1 && j<indices.size()-1)
                ans += (l-indices[j-k]) * (indices[j+1]-r);
            else if(j-k+1==0 && j==indices.size()-1)
                ans += (l+1)*(n-r);
            else if(j-k+1==0)
                ans += (l+1)*(indices[j+1]-r);
            else
                ans += (l-indices[j-k])*(n-r);
        }
        return ans;
    }
};