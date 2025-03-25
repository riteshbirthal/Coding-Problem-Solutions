class Solution {
    public:
        int maximumCandies(vector<int>& candies, long long k) {
            int res = 0, left = 1, right = 1e8, mid;
            long long count;
            while(left<=right){
                mid = (left + right) / 2;
                count = 0;
                for(int x : candies){
                    count += (long long)x / mid;
                }
                if(count>=k){
                    res = mid;
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }
            return res;
        }
    };