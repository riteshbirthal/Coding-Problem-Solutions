class Solution {
    public:
        bool canBeValid(string s, string locked) {
            int n = s.size();
            if(n%2) return false;
            int lock = 0, unlock = 0;
            for(int i = 0; i < n; i++){
                if(locked[i]=='1' && s[i]==')')
                    lock++;
                else
                    unlock++;
                if(lock>unlock)
                    return false;
            }
            lock = 0, unlock = 0;
            for(int i = n-1; i >= 0; i--){
                if(locked[i]=='1' && s[i]=='(')
                    lock++;
                else
                    unlock++;
                if(lock>unlock)
                    return false;
            }
            return true;
        }
    };