class Solution {
    public:
        int numOfSubarrays(vector<int>& arr) {
            int n = arr.size(), odd = 0, even = 1, sum = 0;
            long long res = 0, mod = 1e9 + 7;
            for(int x : arr){
                sum += x%2;
                sum%2 ? odd++ : even++;
                res += sum%2 ? even : odd;
                res %= mod;
            }
            return (int)res;
        }
    };