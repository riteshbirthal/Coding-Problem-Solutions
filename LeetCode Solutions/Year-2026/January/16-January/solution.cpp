class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1), hFences.push_back(m);
        vFences.push_back(1), vFences.push_back(n);
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        int nh = hFences.size(), nv = vFences.size();
        long long res = -1, MOD = 1e9+7;
        unordered_set<int> hDiff;
        for(int i = 0; i < nh; i++)
            for(int j = i+1; j < nh; j++)
                hDiff.insert(hFences[j]-hFences[i]);
        for(int i = 0; i < nv; i++)
            for(int j = i+1; j < nv; j++)
                if(hDiff.find(vFences[j]-vFences[i])!=hDiff.end())
                    res = max(res, (long long)(vFences[j]-vFences[i]));
        return res==-1 ? res : (res*res)%MOD;
    }
};
