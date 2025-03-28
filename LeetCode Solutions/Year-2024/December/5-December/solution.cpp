class Solution {
    public:
        bool canChange(string start, string target) {
            string st1 = "", st2 = "";
            int n = start.size();
            vector<pair<char, int>> v1, v2;
            for(int i = 0; i < n; i++){
                if(start[i]!='_')
                    st1 += start[i], v1.push_back({start[i], i});
                if(target[i]!='_')
                    st2 += target[i], v2.push_back({target[i], i});
            }
            if(st1!=st2) return false;
            n = v1.size();
            for(int i = 0; i < n; i++){
                if((v1[i].first=='L' && v1[i].second<v2[i].second) || (v1[i].first=='R' && v1[i].second>v2[i].second))
                    return false;
            }
            return true;
        }
    };