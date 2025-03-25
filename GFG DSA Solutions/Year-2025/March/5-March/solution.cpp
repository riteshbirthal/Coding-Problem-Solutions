class Solution {
    public:
      static bool sort_func(string a, string b){
          return a.size()>b.size();
      }
      
      int longestStringChain(vector<string>& words) {
          // Code here
          int res = 1, len, n = words.size();
          map<string, int> mp;
          for(string &st : words)
              mp[st] = 1;
          sort(words.begin(), words.end(), sort_func);
          if(words[0].size()==words[n-1].size())
              return res;
          string left, right;
          for(string &st : words){
              len = st.size();
              left = "", right = st;
              for(int i = 0; i < len; i++){
                  right.erase(0, 1);
                  if((left.size() + right.size()) && mp.find(left+right)!=mp.end())
                      mp[left+right] = max(mp[left+right], mp[st] + 1);
                  left += st[i];
              }
              res = max(res, mp[st]);
          }
          return res;
      }
};
  