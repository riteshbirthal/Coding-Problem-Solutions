class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size()==1) return nums;
        sort(nums.begin(), nums.end());
        vector<int> vec;
        vector<vector<int>> vec1;
        for(int i = 0; i<nums.size(); i++){
            vector<int> temp;
            for(int j = i-1; j>=0; j--){
                if(nums[i]%nums[j]==0 && temp.size()<=vec1[j].size()){
                    temp = vec1[j];
                }
            }
            temp.push_back(nums[i]);
            vec1.push_back(temp);
        }
        vec = vec1[0];
        for(int i = 0; i<nums.size(); i++){
            if(vec.size()<vec1[i].size()) vec = vec1[i];
        }
        return vec;
    }
};
