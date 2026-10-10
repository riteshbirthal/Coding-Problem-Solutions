class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        map<int, int> mp;
        int n = nums1.size(), ops = k1+k2;
        for(int i = 0; i < n; i++)
            mp[(abs(nums1[i]-nums2[i]))]++;
        long long res = 0;
        while(ops){
            int x = mp.rbegin()->first, y = mp.rbegin()->second;
            if(x==0) break; 
            if(ops<y){
                mp[x] -= ops;
                mp[x-1] += ops;
            }else{
                mp.erase(x);
                mp[x-1] += y;
            }
            ops -= min(ops, y);
        }
        for(auto x = mp.begin(); x != mp.end(); x++)
            res += ((long long)x->first * (long long)x->first) * (long long)x->second;
        return res;
    }
};
