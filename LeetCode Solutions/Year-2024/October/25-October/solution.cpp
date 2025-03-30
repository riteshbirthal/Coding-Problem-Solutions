class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        auto comp = [] (string a, string b) {
            if(a.length()==b.length())
                return a<=b;
            return a.length() <= b.length();
        };
        sort(folder.begin(), folder.end());
        unordered_set<string> u;
        vector<string> vec;
        string st;
        int flag;
        for(auto f : folder){
            st = "", flag = 1;
            for(int i = 0; i < f.size() && flag; i++){
                st += f[i++];
                while(i<f.size() && f[i]!='/'){
                    st += f[i++];
                }
                i--;
                if(u.find(st)!=u.end())
                    flag = 0;
            }
            if(flag)
                u.insert(f);
        }
        for(auto x = u.begin(); x != u.end(); x++)
            vec.push_back(*x);
        return vec;
    }
};