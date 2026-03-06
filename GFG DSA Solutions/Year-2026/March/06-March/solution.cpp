class Solution {
  public:
    string minWindow(string &s, string &p) {
        // code here
        int left = 0, right = 0, n = s.size(), min_len = INT_MAX, idx = -1;
        string res = "";
        unordered_map<int, int> curr_p_chars, orig_p_chars;
        vector<int> vec(26, 0);
        for(char c : p){
            curr_p_chars[c] = curr_p_chars.find(c)==curr_p_chars.end() ? 1 : curr_p_chars[c]+1;
            vec[c-'a']++;
        }
        orig_p_chars = curr_p_chars;
        while(right<n){
            if(orig_p_chars.find(s[right])!=orig_p_chars.end()){
                vec[s[right]-'a']--;
                if(curr_p_chars.find(s[right])!=curr_p_chars.end())
                    curr_p_chars[s[right]]==1 ? curr_p_chars.erase(s[right]) : curr_p_chars[s[right]]--;
            }
            right += 1;
            while(curr_p_chars.size()==0){
                if(min_len > right-left)
                    min_len = right - left, idx = left;
                if(orig_p_chars.find(s[left])!=orig_p_chars.end())
                    vec[s[left]-'a']==0 ? (curr_p_chars[s[left]]=1, vec[s[left]-'a']++) : vec[s[left]-'a']++;
                left += 1;
            }
        }
        if(idx != -1)
            for(int i = idx; i < idx+min_len; i++)
                res += s[i];
        return res;
    }
};
