class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> vec(26, 0);
        int mx, ans = 0, idx, left, right;
        for(int i = 0; i < s.size(); i++){
            idx = s[i] - 'a';
            // cout << idx << " " << vec[idx] << endl;
            mx = vec[idx];
            left = idx-1, right = idx+1;
            for(int j = 0; j < k; j++){
                if(left>=0){
                    mx = max(mx, vec[left]);
                    left--;
                }
                if(right<26){
                    mx = max(mx, vec[right]);
                    right++;
                }
            }
            vec[idx] = mx + 1;
            // cout << vec[idx] << endl;
        }
        for(int i = 0; i < 26; i++) ans = max(ans, vec[i]);
        return ans;
    }
};