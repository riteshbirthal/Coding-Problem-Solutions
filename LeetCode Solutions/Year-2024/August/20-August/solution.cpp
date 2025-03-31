class Solution {
public:
    int func(vector<int>& piles, int n, int M, int turn, map<vector<int>, int>& mp){
        if(n>=piles.size()) return 0;
        if(mp.find({n, M, turn})!=mp.end()) return mp[{n, M, turn}];
        int ans, sum = 0;
        if(turn){
            ans = INT_MIN;
            for(int i = n; i < min(n + 2*M, (int)piles.size()); i++){
                sum += piles[i];
                ans = max(ans, sum + func(piles, i + 1, max(M, i-n+1), 0, mp));
            }
        }else{
            ans = INT_MAX;
            for(int i = n; i < min(n + 2*M, (int)piles.size()); i++){
                sum += piles[n];
                ans = min(ans, func(piles, i + 1, max(M, i-n+1), 1, mp));
            }
        }
        return mp[{n, M, turn}] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        map<vector<int>, int> mp;
        int ans = func(piles, 0, 1, 1, mp);
        return ans;
    }
};