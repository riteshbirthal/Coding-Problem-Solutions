class Solution {
public:
    bool isPalindrome(string s){
        int l = 0, r = s.size()-1;
        while(l<r){
            if(s[l] != s[r]) return false;
            l++, r--;
        }
        return true;
    }
    void func(string s, int n, string st, vector<string> &vec, map<vector<string>, int> & ans){
        if(n==0){
            if(isPalindrome(st)){
                if(st!="") vec.push_back(st);
                reverse(vec.begin(), vec.end());
                ans[vec]++;
                reverse(vec.begin(), vec.end());
                if(st!="") vec.pop_back();
            }
            return ;
        }
        st += s[n-1];
        if(isPalindrome(st)){
            func(s, n-1, st, vec, ans);
            vec.push_back(st);
            func(s, n-1, "", vec, ans);
            vec.pop_back();
        }else{
            func(s, n-1, st, vec, ans);
        }
        return ;
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> vec;
        map<vector<string>, int> mp;
        vector<string> temp;
        func(s, n, "", temp, mp);
        for(auto x = mp.begin(); x != mp.end(); x++) vec.push_back(x->first);
        return vec;
    }
};