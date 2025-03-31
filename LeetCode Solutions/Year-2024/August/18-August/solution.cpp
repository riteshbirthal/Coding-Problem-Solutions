class Solution {
public:
    int nthUglyNumber(int n) {
        long long k;
        map<long long, int> mp;
        mp[1]++;
        for(int i = 1; i < n; i++){
            k = mp.begin()->first;
            mp[2*k]++;
            mp[3*k]++;
            mp[5*k]++;
            mp.erase(k);
        }
        return mp.begin()->first;
    }
};