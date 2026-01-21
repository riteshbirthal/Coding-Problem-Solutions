class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> vec;
        for(auto & n : nums){
            if(n%2==0){
                vec.push_back(-1);
            }else{
                vec.push_back(n);
                for(int i = 0; n - pow(2, i) >= n/2; i++){
                    if(((n-(int)pow(2, i)) | (n-(int)pow(2, i)+1)) == n)
                        vec[vec.size()-1] = min(vec[vec.size()-1], n-(int)pow(2, i));
                }
            }
        }
        return vec;
    }
};
