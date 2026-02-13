class Solution {
public:
    int maxLenOf2Chars(string s, char a, char b){
        int res = 0, sum = 0, n = s.size();
        unordered_map<int, int> u;
        u[sum] = -1;
        for(int i = 0; i < n; i++){
            if(s[i]!=a && s[i]!=b){
                sum = 0;
                u.clear();
                u[sum] = i;
                continue;
            }
            sum += (s[i]==a ? -1 : 1);
            if(u.find(sum)==u.end())
                u[sum] = i;
            else
                res = max(res, i - u[sum]);
        }
        return res;
    }

    int longestBalanced(string s) {
        int n = s.size(), res = 1, count = 0;
        char ch = '0';
        for(int i = 0; i < n; i++){
            if(ch==s[i])
                count++;
            else
                ch = s[i], count = 1;
            res = max(res, count);
        }
        res = max(res, maxLenOf2Chars(s, 'a', 'b'));
        res = max(res, maxLenOf2Chars(s, 'c', 'b'));
        res = max(res, maxLenOf2Chars(s, 'a', 'c'));
        int count1 = 0, count2 = 0, count3 = 0;
        map<pair<int, int>, int> mp;
        mp[{0, 0}] = -1;
        for(int i = 0; i < n; i++){
            count1 += s[i]=='a';
            count2 += s[i]=='b';
            count3 += s[i]=='c';
            if(mp.find({count1-count2, count1-count3})==mp.end())
                mp[{count1-count2, count1-count3}] = i;
            else
                res = max(res, i - mp[{count1-count2, count1-count3}]);
        }
        return res;
    }
};
