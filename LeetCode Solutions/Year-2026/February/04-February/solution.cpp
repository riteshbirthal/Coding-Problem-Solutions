class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        long long res = -4 * 1e18;
        int n = nums.size();
        vector<long long> ps(n+1, 0);
        for(int i = 0; i < n; i++)
            ps[i+1] = ps[i] + nums[i];
        int l = 0, p = 1, q = 1, r = 0, idx = 0;
        while(l+1<n && r+1<n){
            while(l+1<n && nums[l+1]<=nums[l])
                l++;
            if(l+1==n)
                break;
            p = l+1;
            idx = nums[l]>=0 ? l : -1;
            while(p+1<n && nums[p+1]>nums[p]){
                if(idx==-1 && nums[p]>=0)
                    idx = p;
                p++;
            }
            if(p+1==n)
                break;
            else if(nums[p+1]==nums[p]){
                l = p+1;
                continue;
            }
            q = p+1;
            while(q+1<n && nums[q+1]<nums[q])
                q++;
            if(q+1==n)
                break;
            else if(nums[q+1]==nums[q]){
                l = q+1;
                continue;
            }
            r = q+1;
            res = max(res, max(ps[r+1]-ps[idx!=-1 ? idx : l], ps[r+1]-ps[idx!=-1 ? idx : (p-1)]));
            while(r+1<n && nums[r+1]>nums[r]){
                r++;
                res = max(res, max(ps[r+1]-ps[idx!=-1 ? idx : l], ps[r+1]-ps[idx!=-1 ? idx : (p-1)]));
            }
            if(r+1==n)
                break;
            else if(nums[r+1]==nums[r]){
                l = r+1;
                continue;
            }
            l = q;
        }
        return res;
    }
};
