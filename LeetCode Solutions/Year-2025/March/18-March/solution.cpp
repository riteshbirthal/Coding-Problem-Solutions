class Solution {
    public:
        void addElement(vector<int>& vec, int element){
            for(int i = 0; i < 32; i++){
                if(element&(1<<i))
                    vec[i]++;
            }
            return ;
        }
    
        void removeElement(vector<int>& vec, int element){
            for(int i = 0; i < 32; i++){
                if(element&(1<<i))
                    vec[i]--;
            }
            return ;
        }
    
        bool isPossible(vector<int>& vec){
            for(int x : vec)
                if(x>1)
                    return false;
            return true;
        }
    
        int longestNiceSubarray(vector<int>& nums) {
            vector<int> vec(32, 0);
            int res = 1, count = 0, n = nums.size(), end = 0, start = 0;
            while(end<n){
                addElement(vec, nums[end]);
                while(!isPossible(vec))
                    removeElement(vec, nums[start++]);
                res = max(res, end-start+1);
                end++;
            }
            return res;
        }
    };