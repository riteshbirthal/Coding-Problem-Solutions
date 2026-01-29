class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        long long left = 0, right = 1e12, mid, res = 0, temp_k, sum;
        vector<long long> temp_vec;
        if(n<=r){
            for(int x : stations)
                res += (long long)x;
            res += k;
            return res;
        }
        while(left<=right){
            mid = (left + right) / 2;
            temp_k = k, sum = 0;
            temp_vec = vector<long long>(stations.begin(), stations.end());
            int lt = 0, rt = 0;
            while(rt<n || lt<n-r){
                if(rt<n)
                    sum += temp_vec[rt];
                if(rt<r){
                    rt++;
                    continue;
                }
                if(sum<mid){
                    temp_vec[min(n-r-1, max(rt, r-1))] += mid - sum;
                    temp_k -= mid - sum;
                    sum = mid;
                }
                if(rt-lt+1 == 2*r+1 || rt==n)
                    sum -= temp_vec[lt++];
                if(rt<n)
                    rt++;
            }
            if(temp_k>=0)
                res = mid, left = mid + 1;
            else
                right = mid - 1;
        }
        return res;
    }
};
