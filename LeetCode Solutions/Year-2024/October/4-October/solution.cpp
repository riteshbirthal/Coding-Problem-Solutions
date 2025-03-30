class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        long long n = skill.size(), ans = 0, sum = 0;
        sum = skill[0] + skill[n-1];
        for(int i = 0; i < n/2; i++){
            if(sum!=skill[i]+skill[n-1-i])
                return -1;
            ans += (long long)skill[i]*(long long)skill[n-1-i];
        }
        return ans;
    }
};