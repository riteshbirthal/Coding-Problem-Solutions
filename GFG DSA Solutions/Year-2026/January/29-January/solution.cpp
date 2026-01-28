class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        vector<int> count(26, 0), ids(26, 0);
        set<pair<int, char>> st;
        string res = "";
        int id = 1;
        for(char c : s){
            if(count[c-'a']==0){
                count[c-'a'] = 1;
                st.insert({id, c});
                ids[c-'a'] = id;
                id++;
            }else{
                count[c-'a']++;
                if(st.find({ids[c-'a'], c})!=st.end())
                    st.erase({ids[c-'a'], c});
            }
            if(st.size()==0)
                res += '#';
            else
                res += (*st.begin()).second;
        }
        return res;
    }
};
