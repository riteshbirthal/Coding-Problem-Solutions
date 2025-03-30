class Solution {
public:
    long long func(vector<long long>& r, vector<long long>& f, int n, int m, vector<vector<long long>>& v){
        if(n==0) return 0;
        if(m==0) return LONG_MAX;
        if(v[n][m]!=-1) return v[n][m];
        long long ans = LONG_MAX, temp;
        ans = func(r, f, n, m-1, v);
        temp = func(r, f, n-1, m-1, v);
        if(temp != LONG_MAX)
            ans = min(ans, abs(f[m-1]-r[n-1]) + temp);
        return v[n][m] = ans;
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size(), m = factory.size();
        vector<long long> r, f;
        for(auto x : factory)
            while(x[1]--)
                f.push_back(x[0]);
        for(auto x : robot)
            r.push_back(x);
        sort(r.begin(), r.end());
        sort(f.begin(), f.end());
        m = f.size();
        vector<vector<long long>> vec(n+1, vector<long long>(m+1, -1));
        long long ans;
        ans = func(r, f, n, m, vec);
        return ans;
    }
};