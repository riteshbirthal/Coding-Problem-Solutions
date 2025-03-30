class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size(), count = 1, mx;
        vector<int> res, right(26, -1);
        for(int i = n-1; i >= 0; i--)
            if(right[s[i]-'a']==-1)
                right[s[i]-'a'] = i;
        for(int i = 0; i < n; i++){
            mx = max(mx, right[s[i]-'a']);
            if(i==mx)
                res.push_back(count), count = 1;
            else
                count++, mx = max(mx, right[s[i]-'a']);
        }
        return res;
    }
};