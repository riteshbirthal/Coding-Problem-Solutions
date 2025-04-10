class Solution {
public:
    vector<vector<long long>> memo;
    long long dp(int i, bool tight, const string& M, const string& s, int limit, int n, int k) {
        if (i == n) {
            return 1;
        }
        if (memo[i][tight] != -1) {
            return memo[i][tight];
        }

        long long res = 0;
        if (i < n - k) {
            int upper = min(limit, tight ? M[i] - '0' : 9);
            for (int digit = 0; digit <= upper; digit++) {
                bool new_tight = tight && (digit == M[i] - '0');
                res += dp(i + 1, new_tight, M, s, limit, n, k);
            }
        } else {
            int required = s[i - (n - k)] - '0';
            if (!tight || required <= M[i] - '0') {
                bool new_tight = tight && (required == M[i] - '0');
                res += dp(i + 1, new_tight, M, s, limit, n, k);
            }
        }
        memo[i][tight] = res;
        return res;
    }
    string pad_zero(string s, int n) {
        while (s.size() < n) {
            s = "0" + s;
        }
        return s;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string M_finish = to_string(finish);
        int n = M_finish.size();
        int k = s.size();

        if (k > n) {
            return 0;
        }
        memo.assign(n + 1, vector<long long>(2, -1));
        long long count_finish = dp(0, true, M_finish, s, limit, n, k);

        if (start == 0) { 
            return count_finish;
        }
        string M_start = pad_zero(to_string(start - 1), n);
        memo.assign(n + 1, vector<long long>(2, -1));
        long long count_start_minus_1 = dp(0, true, M_start, s, limit, n, k);

        return count_finish - count_start_minus_1;
    }
};
