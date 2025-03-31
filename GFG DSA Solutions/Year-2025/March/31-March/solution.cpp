
class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        int n = s.size(), mx = 0, res = 0;
        vector<int> vec(26, 0);
        for(int i = n-1; i >= 0; i--)
            if(!vec[s[i]-'a'])
                vec[s[i]-'a'] = i;
        for(int i = 0; i < n; i++){
            mx = max(mx, vec[s[i]-'a']);
            if(mx==i)
                res++;
        }
        return res;
    }
};
