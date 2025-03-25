class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            vector<vector<int>> res;
            int idx1 = 0, idx2 = 0, n1 = nums1.size(), n2 = nums2.size();
            while(idx1<n1 || idx2<n2){
                if(idx1<n1 && idx2<n2){
                    if(nums1[idx1][0]==nums2[idx2][0]){
                        res.push_back({nums1[idx1][0], nums1[idx1++][1] + nums2[idx2++][1]});
                    }else{
                        res.push_back(nums1[idx1][0]<nums2[idx2][0] ? nums1[idx1++] : nums2[idx2++]);
                    }
                }else{
                    res.push_back(idx1<n1 ? nums1[idx1++] : nums2[idx2++]);
                }
            }
            return res;
        }
    };