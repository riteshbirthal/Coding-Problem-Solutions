class Solution {
  public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        // Your code here
        int n = s1.size(), idx = -1, mn = INT_MAX, m, flag, new_idx;
        if(n!=s2.size()) return false;
        vector<int> vec1(26, 0), vec2(26, 0), idxes;
        for(int i = 0; i < n; i++){
            vec1[s1[i]-'a']++, vec2[s2[i]-'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(vec1[i] && mn>vec1[i]) idx = i, mn = vec1[i];
            if(vec1[i]!=vec2[i]) return false;
        }
        if(n==mn) return true;
        // cout << idx << " " << mn << endl;
        for(int i = 0; i < n; i++){
            if(s2[i]=='a'+idx) idxes.push_back(i);
            if(s1[i]=='a'+idx) new_idx = i;
        }
        m = idxes.size();
        for(int i = 0; i < m; i++){
            flag = 1;
            for(int j = 0; j < n && flag; j++){
                flag = (s2[(j+idxes[i])%n]==s1[(j+new_idx)%n]);
            }
            if(flag) return true;
        }
        return false;
    }
};