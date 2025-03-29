class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size(), flag = 0, idx = -1, visit;
        vector<int> vec;
        for(int i = 0; i < n-k+1; i++){
            if(flag){
                if(nums[i+k-1]!=1+nums[i+k-2])
                    flag = 0;
            }
            if(flag==0){
                flag = 1, idx = -1;
                for(int j = i+1; j < i+k; j++){
                    if(nums[j]!=1+nums[j-1]){
                        idx = j-1;
                        flag = 0;
                        break;
                    }
                }
                if(!flag){
                    while(i<=idx){
                        vec.push_back(-1);
                        i++;
                    }
                    i--;
                }
            }
            if(flag)
                vec.push_back(nums[i+k-1]);
        }
        while(vec.size()>n-k+1) vec.pop_back();
        return vec;
    }
};