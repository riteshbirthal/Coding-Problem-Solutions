class Solution {
  public:
    int myAtoi(char *s) {
        // Your code here
        vector<char> v;
        while(*s){
            if(*s)
                v.push_back(*s);
            s++;
        }
        int n = v.size(), ans = 0, sign = 1, idx = n;
        long long num = 0;
        for(int i = 0; i < n && idx==n; i++){
            if(v[i]!=' ') idx = i;
        }
        if(v[idx]=='+' || v[idx]=='-'){
            sign = v[idx]=='-' ? -1 : 1;
            idx++;
        }
        for(int i = idx; i < n && v[i]>='0' && v[i]<='9'; i++){
            num = num*10 + v[i] - '0';
        }
        num *= sign;
        if(num<INT_MIN) ans = INT_MIN;
        else if(num>INT_MAX) ans = INT_MAX;
        else ans = num;
        return ans;
    }
};