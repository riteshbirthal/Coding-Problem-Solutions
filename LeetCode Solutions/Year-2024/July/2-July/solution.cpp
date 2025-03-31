class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), k;
        vector<int> vec1(1001, 0), vec2(1001, 0);
        for(int i = 0; i < n1; i++)
            vec1[nums1[i]]++;
        for(int i = 0; i < n2; i++)
            vec2[nums2[i]]++;
        vector<int> ans;
        for(int i = 0; i < 1001; i++){
            k = 0;
            if(min(vec1[i], vec2[i]))
                k = min(vec1[i], vec2[i]);
            while(k--)
                ans.push_back(i);
        }
        return ans;
    }
};