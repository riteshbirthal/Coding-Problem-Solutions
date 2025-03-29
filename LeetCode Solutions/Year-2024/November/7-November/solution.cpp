class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = 0, count, num;
        for(int i = 0; i < 32; i++){
            count = 0, num = 1 << i;
            for(auto x : candidates){
                if(num & x) count++;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};