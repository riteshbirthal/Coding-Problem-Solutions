class Solution {
    public:
        int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
            int res = 0, n1 = nums1.size(), n2 = nums2.size();
            if(n1%2){
                for(int x : nums2)
                    res ^= x;
            }
            if(n2%2){
                for(int x : nums1)
                    res ^= x;
            }
            return res;
        }
    };