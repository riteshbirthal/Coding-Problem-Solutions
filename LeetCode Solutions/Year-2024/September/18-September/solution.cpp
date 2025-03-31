class Solution {
public:
    static bool sort_func(int &a, int & b){
        string ab = to_string(a) + to_string(b), ba = to_string(b) + to_string(a);
        return ab > ba;
    }

    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), sort_func);
        string ans = "";
        for(int i = 0; i < n; i++){
            ans += to_string(nums[i]);
        }
        reverse(ans.begin(), ans.end());
        while(ans.size() && ans[ans.size()-1]=='0') ans.pop_back();
        if(ans.size()==0) ans = "0";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};