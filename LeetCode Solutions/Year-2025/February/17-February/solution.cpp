class Solution {
    public:
        vector<int> fact;
        int totalCases(vector<int> vec){
            int res = fact[accumulate(vec.begin(), vec.end(), 0)];
            for(int x : vec)
                res /= fact[x];
            return res;
        }
    
        int func(string tiles, int idx, vector<int>& vec, map<vector<int>, int>& mp){
            int res = 0;
            if(idx==tiles.size()){
                res = mp.find(vec)==mp.end() ? totalCases(vec) : 0;
                mp[vec]++;
                return res;
            }
            res = func(tiles, idx + 1, vec, mp);
            vec[tiles[idx]-'A']++;
            res += func(tiles, idx + 1, vec, mp);
            vec[tiles[idx]-'A']--;
            return res;
        }
    
        int numTilePossibilities(string tiles) {
             vector<int> vec(26, 0);
             fact = vector<int>(10, 1);
             for(int i = 2; i < 10; i++)
                fact[i] = i*fact[i-1];
             map<vector<int>, int> mp;
             int res = func(tiles, 0, vec, mp);
             return res - 1;
        }
    };