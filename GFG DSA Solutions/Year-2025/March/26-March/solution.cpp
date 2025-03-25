class Solution {
    public:
      int wordBreak(string &s, vector<string> &dictionary) {
          // code here
          unordered_set<string> words(dictionary.begin(), dictionary.end());
          int n = s.size();
          vector<int> dp(n+1, 0);
          dp[n] = 1;
          for(int i = n-1; i >= 0; i--){
              for(int j = i; j < min(n, i+101) && !dp[i]; j++){
                  dp[i] = words.find(s.substr(i, j-i+1))!=words.end() && dp[j+1];
              }
          }
          return dp[0];
      }
  };