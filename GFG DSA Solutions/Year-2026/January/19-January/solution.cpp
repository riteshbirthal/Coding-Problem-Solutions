class Solution {
  public:
    string removeKdig(string &s, int k) {
        // code here
        string res = "";
        for(char c : s){
            while(k && res.size() && res[res.size()-1]>c)
                res.pop_back(), k -= 1;
            res.push_back(c);
        }
        while(k && res.size())
            res.pop_back(), k--;
        if(res.size()==0)
            return "0";
        reverse(res.begin(), res.end());
        while(res[res.size()-1]=='0')
            res.pop_back();
        if(res.size()==0)
            return "0";
        reverse(res.begin(), res.end());
        return res;
    }
};
