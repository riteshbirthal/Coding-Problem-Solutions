class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long res = 0, area, len;
        int n = bottomLeft.size();
        vector<int> bL1, tR1, bL2, tR2, bL, tR;
        for(int i = 0; i < n; i++){
            bL1 = bottomLeft[i], tR1 = topRight[i];
            for(int j = i+1; j < n; j++){
                bL2 = bottomLeft[j], tR2 = topRight[j];
                bL = vector<int>{max(bL1[0], bL2[0]), max(bL1[1], bL2[1])};
                tR = vector<int>{min(tR1[0], tR2[0]), min(tR1[1], tR2[1])};
                len = min(max(0, tR[0]-bL[0]), max(0, tR[1]-bL[1]));
                res = max(res, len*len);
                if(len==(long long)min(tR1[0]-bL1[0], tR1[1]-bL1[1]))
                    break;
            }
        }
        return res;
    }
};
