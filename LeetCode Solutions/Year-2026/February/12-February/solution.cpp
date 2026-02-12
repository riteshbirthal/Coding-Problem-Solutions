class Solution {
public:
    bool isValid(vector<int>& vec, int freq){
        bool res = true;
        for(int x : vec)
            if(x)
                res = res && x==freq;
        return res;
    }
    
    int longestBalanced(string s) {
        vector<int> vec(26, 0), temp(26, 0);
        int n = s.size(), res = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                vec[s[j]-'a'] += 1;
                int x = vec[s[j]-'a'];
                if(isValid(vec, x))
                    res = max(res, j-i+1);
            }
            vec = temp;
        }
        return res;
    }
};
