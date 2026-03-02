class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size(), res = 0;
        vector<int> orig(n, 0);
        for(int i = 0; i < n; i++)
            for(int j = n-1; j >= 0 && grid[i][j]==0; j--)
                orig[i]++;
        priority_queue<int> pq(orig.begin(), orig.end());
        for(int i = 0; i < n; i++){
            if(pq.top()<n-1-i)
                return -1;
            pq.pop();
        }
        int idx, count;
        for(int i = 0; i < n-1; i++){
            idx = i;
            while(orig[idx]<n-1-i)
                idx++;
            count = orig[idx];
            for(int j = idx; j > i; j--)
                orig[j] = orig[j-1];
            orig[i] = count;
            res += idx - i;
        }
        return res;
    }
};
