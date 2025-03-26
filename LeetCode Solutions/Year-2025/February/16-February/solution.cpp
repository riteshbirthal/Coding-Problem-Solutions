class Solution {
    public:
        bool validVector(vector<int> v){
            bool res = true;
            for(int x : v)
                res = res && x;
            return res;
        }
        vector<int> func(vector<int>& vec, vector<int>& r, int idx){
            int n = r.size();
            if(idx==n)
                return validVector(r) ? r : vector<int>(n, 0);
            if(r[idx])
                return func(vec, r, idx+1);
            vector<int> res(n, 0);
            for(int i = vec.size()-1; i >= 0; i--){
                if(vec[i] && idx+i+1<n && !r[idx+i+1]){
                    vec[i] = 0;
                    r[idx] = i+1;
                    if(i)
                        r[idx+i+1] = i+1;
                    // res = max(res, func(vec, r, idx+1));
                    res = func(vec, r, idx+1);
                    if(validVector(res))
                        return res;
                    r[idx] = 0;
                    if(i)
                        r[idx+i+1] = 0;
                    vec[i] = 1;
                }else if(vec[i] && i==0){
                    vec[i] = 0;
                    r[idx] = 1;
                    // res = max(res, func(vec, r, idx+1));
                    res = func(vec, r, idx+1);
                    if(validVector(res))
                        return res;
                    r[idx] = 0;
                    vec[i] = 1;
                }
            }
            return res;
        }
        vector<int> constructDistancedSequence(int n) {
            vector<int> res, vec(n, 1), v(2*n-1, 0);
            res = func(vec, v, 0);
            return res;
        }
    };