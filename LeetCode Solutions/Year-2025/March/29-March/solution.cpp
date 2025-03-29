class Solution {
    public:
        vector<int> getPrimeScoreArray(){
            vector<int> vec(100001, 0);
            for(int i = 2; i < 100001; i++){
                if(vec[i])
                    continue;
                for(int j = 1; j*i < 100001; j++)
                    vec[j*i] += 1;
            }
            return vec;
        }
    
        int power(int a, long long b){
            if(b == 0)
                return 1;
            long long res = 1, mod = 1e9 + 7;
            int p = power(a, b/2);
            if(b%2)
                res *= (long long)a * p, res %= mod, res *= p;
            else
                res *= p, res %= mod, res *= p;
            return (int)(res%mod);
        }
    
        int maximumScore(vector<int>& nums, int k) {
            long long res = 1, mod = 1e9+7;
            int n = nums.size();
            vector<int> p_score = getPrimeScoreArray(), left(n, 1), right(n, 1);
            stack<pair<int, int>> st;
            st.push({INT_MAX, -1});
            for(int i = 0; i < n; i++){
                while(p_score[nums[i]]>st.top().first)
                    st.pop();
                left[i] = i - st.top().second;
                st.push({p_score[nums[i]], i});
            }
            while(st.size())
                st.pop();
            st.push({INT_MAX, n});
            for(int i = n-1; i >= 0; i--){
                while(p_score[nums[i]]>=st.top().first)
                    st.pop();
                right[i] = st.top().second - i;
                st.push({p_score[nums[i]], i});
            }
            priority_queue<pair<int, int>> pq;
            pair<int, int> pr;
            for(int i = 0; i < n; i++)
                pq.push({nums[i], i});
            while(k){
                pr = pq.top(), pq.pop();
                int dk = min((long long)k, (long long)left[pr.second]*right[pr.second]);
                res *= power(pr.first, dk);
                res %= mod;
                k -= dk;
            }
            return (int)res;
        }
    };