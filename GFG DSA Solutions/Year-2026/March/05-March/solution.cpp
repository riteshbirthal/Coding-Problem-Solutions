class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n = s.size(), left = 0, right = 0, res = -1;
        unordered_map<int, int> count;
        while(right<n){
            count[s[right]] = count.find(s[right])==count.end() ? 1 : count[s[right]]+1;
            if(count.size()==k)
                res = max(res, right-left+1);
            while(count.size()>k){
                count[s[left]]==1 ? count.erase(s[left]) : count[s[left]]--;
                left++;
            }
            right++;
        }
        return res;
    }
};
