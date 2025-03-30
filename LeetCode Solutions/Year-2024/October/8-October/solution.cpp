class Solution {
    public:
        int minSwaps(string s) {
            int ans = 0, l = 0, r = s.size()-1, l_flag, r_flag;
            stack<char> left, right;
            while(l<r){
                l_flag = 1, r_flag = 1;
                if(s[l]==']' && left.size()){
                    left.pop();
                    l++;
                    l_flag = 0;
                }else if(s[l]=='['){
                    left.push('[');
                    l++;
                    l_flag = 0;
                }
                if(s[r]=='[' && right.size()){
                    right.pop();
                    r--;
                    r_flag = 0;
                }else if(s[r]==']'){
                    right.push('[');
                    r--;
                    r_flag = 0;
                }
                if(l_flag && r_flag){
                    ans++;
                    l++, r--;
                    left.push('[');
                    right.push(']');
                }
            }
            return ans;
        }
    };