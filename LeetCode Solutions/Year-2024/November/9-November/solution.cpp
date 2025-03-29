class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x, num = 1, count = 1;
        vector<int> vec(63, 0);
        map<int, int> mp;
        for(int i = 0; i < 63; i++){
            vec[i] = ans&1;
            if(!vec[i]) mp[count] = i, count++;
            ans = ans >> 1;
        }
        n--;
        for(int i = 0; n; i++){
            vec[mp[i+1]] = n&1;
            n = n >> 1;
        }
        ans = 0;
        for(int i = 0; i < 63; i++){
            if(vec[i]) ans += (long long) 1 << i;
        }
        return ans;
    }
};