class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if(n+k-1 < pow(2, k))
            return false;
        set<string> st;
        string bin = "";
        for(int i = 0; i < n; i++){
            bin += s[i];
            if(i<k-1)
                continue;
            st.insert(bin);
            bin = bin.substr(1);
        }
        return st.size()==pow(2,k);
    }
};
