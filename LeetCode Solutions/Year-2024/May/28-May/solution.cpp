class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size(), left = 0, right = 0, ans = 0;
        vector<int> vec(n, 0);
        for (int i = 0; i < n; i++)
            vec[i] = abs(s[i] - t[i]);
        while (right < n) {
            while (maxCost >= 0 && right < n)
                maxCost -= vec[right++];

            if (maxCost < 0)
                ans = max(ans, right - left - 1);
            else
                ans = max(ans, right - left);

            while (maxCost < 0)
                maxCost += vec[left++];
        }
        return ans;
    }
};