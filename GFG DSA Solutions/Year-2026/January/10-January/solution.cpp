class Solution {
  public:
    int findSubstr(string& s, int k){
        int res = 0, n = s.size(), left = 0, right = 0;
        unordered_map<char, int> u;
        while(right<n){
            u.find(s[right])==u.end() ? u[s[right]] = 1 : u[s[right]]++;
            while(u.size()>k){
                u[s[left]]==1 ? u.erase(s[left]) : u[s[left]]--;
                left++;
            }
            res += right - left + 1;
            right++;
        }
        return res;
    }
    
    int countSubstr(string& s, int k) {
        // code here.
        int res = 0;
        res = findSubstr(s, k) - findSubstr(s, k-1);
        return res;
    }
};
