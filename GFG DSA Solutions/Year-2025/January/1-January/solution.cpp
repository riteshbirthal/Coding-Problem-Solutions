// User function Template for C++

class Solution {
    public:
      vector<vector<string>> anagrams(vector<string>& arr) {
          // code here
          vector<vector<string>> res;
          map<string, vector<string>> mp;
          string str;
          for(string st : arr){
              str = st;
              sort(str.begin(), str.end());
              if(mp.find(str)==mp.end()){
                  mp[str] = {st};
              }else{
                  mp[str].push_back(st);
              }
          }
          for(auto x = mp.begin(); x != mp.end(); x++){
              res.push_back(x->second);
          }
          sort(res.begin(), res.end());
          return res;
      }
  };