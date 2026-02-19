class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0, n = s.size();
        vector<int> vec(n+1, 0);
        for(int i = 0; i < n; i++)
            vec[i+1] = vec[i] + s[i]-'0';
        int count = 0;
        char ch = '0';
        for(int i = 0; i < n; i++){
            if(ch!=s[i])
                count = 0, ch = s[i];
            count++;
            if(2*count>i+1)
                continue;
            if(i+1-2*count>=0 && (vec[i+1]-vec[i+1-2*count])==count)
                res++;
        }
        return res;
    }
};
