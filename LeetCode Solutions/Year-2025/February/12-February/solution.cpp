class Solution {
    public:
        int digitSum(int n){
            int sum = 0;
            while(n){
                sum += n%10;
                n /= 10;
            }
            return sum;
        }
        int maximumSum(vector<int>& nums) {
            int res = -1, first, second;
            vector<priority_queue<int>> vec(100);
            for(int x : nums){
                vec[digitSum(x)].push(x);
            }
            for(int i = 0; i < 100; i++){
                if(vec[i].size()>1){
                    first = vec[i].top();
                    vec[i].pop();
                    second = vec[i].top();
                    res = max(res, first + second);
                }
            }
            return res;
        }
    };