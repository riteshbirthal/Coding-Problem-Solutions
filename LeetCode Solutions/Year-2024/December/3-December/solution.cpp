class Solution {
    public:
        string addSpaces(string s, vector<int>& spaces) {
            string ans = "";
            int n = spaces.size(), idx, count = 0;
            for(int i = 0; i < n; i++){
                idx = spaces[i];
                while(ans.size()<idx+count){
                    ans.push_back(s[ans.size()-count]);
                }
                ans.push_back(' ');
                count++;
            }
            while(ans.size()<n+s.size()){
                ans.push_back(s[ans.size()-count]);
            }
            return ans;
        }
    };