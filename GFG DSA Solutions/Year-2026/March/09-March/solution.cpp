class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        int n = s.size(), f_idx = -1, l_idx = -1;
        string st = s;
        vector<int> digits(10, 0);
        for(char c : s)
            digits[c - '0']++;
        int idx = 9, digit = -1;
        for(int i = 0; i < n; i++){
            while(idx>=0 && digits[idx]==0)
                idx--;
            if(idx!=(s[i]-'0')){
                f_idx = i;
                digit = idx;
                break;
            }
            digits[idx]--;
        }
        if(f_idx!=-1){
            for(int i = 0; i < n; i++)
                if((s[n-1-i]-'0')==idx){
                    l_idx = n-1-i;
                    break;
                }
            s[l_idx] = s[f_idx];
            s[f_idx] = idx+'0';
        }
        return s;
    }
};
