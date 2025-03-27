class Solution {
    public:
      void func(vector<int>& vec, string &s, unordered_set<string>& u){
          bool isEnd = true;
          for(int i = 0; i < 26; i++){
              if(vec[i]) isEnd = false;
          }
          if(isEnd){
              u.insert(s);
              return ;
          }
          
          for(int i = 0; i < 26; i++){
              if(vec[i]){
                  vec[i]--;
                  s += 'A' + i;
                  func(vec, s, u);
                  s.pop_back();
                  vec[i]++;
              }
          }
          return ;
      }
      
      vector<string> findPermutation(string &s) {
          // Code here there
          unordered_set<string> u;
          vector<int> vec(26, 0);
          for(char ch : s)
              vec[ch-'A']++;
          string st = "";
          func(vec, st, u);
          vector<string> res;
          for(auto x = u.begin(); x != u.end(); x++)
              res.push_back(*x);
          return res;
      }
  };
  