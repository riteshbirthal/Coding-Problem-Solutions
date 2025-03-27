class Solution {
    public:
        int countPalindromicSubsequence(string s) {
            vector<int> start(26, -1), end(26, -1);
            vector<unordered_map<int, int>> vec;
            unordered_map<int, int> u, u1, u2;
            int n = s.size(), res = 0;
            for(int i = 0; i < n; i++){
                u.find(s[i])==u.end() ? u[s[i]] = 1 : u[s[i]] += 1;
                vec.push_back(u);
                if(start[s[i]-'a']==-1){
                    start[s[i]-'a'] = i;
                }
                end[s[i]-'a'] = i;
            }
            for(int i = 0; i < 26; i++){
                if(start[i]==-1){
                    continue;
                }
                u1 = vec[start[i]];
                u2 = vec[end[i]];
                for(auto x = u1.begin(); x != u1.end(); x++){
                    if(u2[x->first]==x->second){
                        u2.erase(x->first);
                    }else{
                        u2[x->first] -= x->second;
                    }
                }
                if(u2.find('a'+i)!=u2.end())
                    u2['a'+i]==1 ? u2.erase('a'+i) : u2['a'+i] -= 1;
                res += u2.size();
            }
            return res;
        }
    };