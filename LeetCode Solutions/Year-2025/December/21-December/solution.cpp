class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int res = 0, n = strs.size(), m = strs[0].size();
        vector<bool> vec(n-1, false), prev(n-1, false);
        bool flag;
        for(int i = 0; i < m; i++){
            flag = true;
            for(int j = 1; j < n; j++){
                if(!vec[j-1] && strs[j][i]<strs[j-1][i])
                    flag = false;
                else if(strs[j][i] > strs[j-1][i])
                    vec[j-1] = true;
            }
            if(!flag)
                vec = prev, res += 1;
            flag = true;
            for(int j = 1; j < n; j++)
                flag = flag && vec[j-1];
            if(flag)
                break;
            prev = vec;
        }
        return res;
    }
};
