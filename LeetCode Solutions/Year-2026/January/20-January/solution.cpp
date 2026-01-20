class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> vec;
        for(auto &n : nums){
            for(int i = 0; i < 1001; i++){
                if((i | (i+1)) == n){
                    vec.push_back(i);
                    break;
                }else if(i==1000){
                    vec.push_back(-1);
                }
            }
        }
        return vec;
    }
};
