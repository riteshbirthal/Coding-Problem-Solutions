class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size(), count = 0, ptr = 0;
        vector<int> pos;
        for(int i = 0; i < n; i++){
            if(s[i]=='0')
                count++, pos.push_back(i);
        }
        long long ans = 0;
        n = pos.size();
        for(int i = 0; i < n; i++){
            ans += max(0, pos[i] - ptr);
            ptr++;
        }
        return ans;
    }
};