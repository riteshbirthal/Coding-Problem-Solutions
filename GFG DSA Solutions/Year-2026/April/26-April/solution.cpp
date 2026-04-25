class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        // code here
        set<int> as(a.begin(), a.end()), bs(b.begin(), b.end()), cs(c.begin(), c.end());
        vector<int> res;
        for(auto x = as.begin(); x != as.end(); x++)
            if(bs.find(*x)!=bs.end() && cs.find(*x)!=cs.end())
                res.push_back(*x);
        return res;
    }
};
