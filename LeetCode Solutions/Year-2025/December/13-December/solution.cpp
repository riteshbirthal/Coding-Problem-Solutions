class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        map<string, vector<string>> coupons;
        string c, b;
        bool valid;
        for(int i = 0; i < n; i++){
            c = code[i], b = businessLine[i];
            valid = isActive[i] && (b=="electronics" || b=="grocery" || b=="pharmacy" || b=="restaurant") && c.size();
            if(!valid)
                continue;
            for(char ch : c)
                valid = valid && (ch=='_' || ('0'<=ch && ch<='9') || ('a'<=ch && ch<='z') || ('A'<=ch && ch<='Z'));
            if(valid)
                coupons[b].push_back(c);
        }
        vector<string> res, vec;
        for(auto x : coupons){
            vec = x.second;
            sort(vec.begin(), vec.end());
            for(auto cp : vec)
                res.push_back(cp);
        }
        return res;
    }
};
