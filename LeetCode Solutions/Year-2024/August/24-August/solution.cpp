class Solution {
public:
    bool palindrome(string s){
        int l = 0, r = s.size() - 1;
        while(l<r){
            if(s[l]!=s[r])
                return false;
            l++, r--;
        }
        return true;
    }
    bool checkall9s(string s){
        int n = s.size();
        for(int i = 0; i < n; i++)
            if(s[i]!='9')
                return false;
        return true;
    }
    string nearestPalindromic(string n) {
        if(n.size()<7){
            for(int i = 1; true; i++){
                if(palindrome(to_string(stoi(n)-i))){
                    return to_string(stoi(n)-i);
                }else if(palindrome(to_string(stoi(n)+i))){
                    return to_string(stoi(n)+i);
                }
            }
        }
        if(checkall9s(n))
            return to_string(stoll(n)+2);
        int siz = (n.size() + 1) / 2;
        string prefix = "", new_prefix, rev_prefix, ans = n;
        for(int i = 0; i < siz; i++)
            prefix += n[i];

        map<string, int> mp;
        new_prefix = prefix;
        reverse(new_prefix.begin(), new_prefix.end());
        mp[prefix + new_prefix]++;

        new_prefix = prefix;
        new_prefix.pop_back();
        if(new_prefix.size())
            reverse(new_prefix.begin(), new_prefix.end()), mp[prefix + new_prefix]++;

        new_prefix = to_string(stoll(prefix) + 1);
        rev_prefix = new_prefix;
        reverse(rev_prefix.begin(), rev_prefix.end());
        mp[new_prefix + rev_prefix]++;

        new_prefix = to_string(stoll(prefix) + 1);
        rev_prefix = new_prefix;
        rev_prefix.pop_back();
        if(rev_prefix.size())
            reverse(rev_prefix.begin(), rev_prefix.end()), mp[new_prefix + rev_prefix]++;

        new_prefix = to_string(stoll(prefix) - 1);
        rev_prefix = new_prefix;
        reverse(rev_prefix.begin(), rev_prefix.end());
        mp[new_prefix + rev_prefix]++;

        new_prefix = to_string(stoll(prefix) - 1);
        rev_prefix = new_prefix;
        rev_prefix.pop_back();
        if(rev_prefix.size())
            reverse(rev_prefix.begin(), rev_prefix.end()), mp[new_prefix + rev_prefix]++;

        mp.erase(n);
        long long mx = LONG_LONG_MAX;
        ans = mp.begin()->first;
        for(auto x = mp.begin(); x != mp.end(); x++){
            cout << x->first << endl;
            if(mx>=abs(stoll(x->first) - stoll(n))){
                if(mx==abs(stoll(x->first) - stoll(n))){
                    if(ans.size()>x->first.size())
                        ans = x->first;
                    else if(ans.size()==x->first.size())
                        ans = to_string(min(stoll(ans), stoll(x->first)));
                }else{
                    ans = x->first;
                }
                mx = abs(stoll(x->first) - stoll(n));
            }
        }
        return ans;
    }
};