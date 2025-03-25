class Solution {
    public:
        long long repairCars(vector<int>& ranks, int cars) {
            long long res = LONG_MAX, left = 0, right = 1e15, mid;
            int tempCars, n = ranks.size();
            while(left<=right){
                mid = (left + right) / 2;
                tempCars = cars;
                for(int i = 0; i < n; i++){
                    if(mid/ranks[i] && tempCars){
                        tempCars -= min((int)sqrt(mid/ranks[i]), tempCars);
                    }
                }
                if(!tempCars){
                    res = mid;
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
            return res;
        }
    };