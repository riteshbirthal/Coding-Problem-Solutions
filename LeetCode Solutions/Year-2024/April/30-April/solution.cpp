class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long res = 0;
        map<int, int> mp;
        int num = 0;
        mp[0] = 1;
        for(char ch : word){
            num = num ^ (1<<(ch-'a'));
            res += mp.find(num)!=mp.end() ? mp[num] : 0;
            for(int i = 0; i < 11; i++){
                res += mp.find(num^(1<<i))!=mp.end() ? mp[num^(1<<i)] : 0;
            }
            mp.find(num)==mp.end() ? mp[num] = 1 : mp[num]++;
        }
        return res;
    }
};