class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int res = INT_MAX, countW = 0, countB = 0, n = blocks.size();
            for(int i = 0; i < n; i++){
                blocks[i]=='W' ? countW++ : countB++;
                if(i<k-1)
                    continue;
                res = min(res, countW);
                blocks[i-k+1]=='W' ? countW-- : countB--;
            }
            return res;
        }
    };