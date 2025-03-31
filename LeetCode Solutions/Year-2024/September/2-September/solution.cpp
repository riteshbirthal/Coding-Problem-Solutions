class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long sum = 0;
        for(auto x : chalk){
            sum += (long long)x;
        }
        k %= sum;
        for(int i = 0; i < n; i++){
            if(k<chalk[i])
                return i;
            else
                k -= chalk[i];
        }
        return 0;
    }
};