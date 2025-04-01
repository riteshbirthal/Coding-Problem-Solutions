class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ans;
        vector<int> vec = score;
        sort(vec.begin(), vec.end());
        map<int, int> mp;
        for(int i = 0; i < n; i++) mp[vec[i]] = n - i;
        for(int i = 0; i < n; i++){
            if(mp[score[i]]==1) ans.push_back("Gold Medal");
            else if(mp[score[i]]==2) ans.push_back("Silver Medal");
            else if(mp[score[i]]==3) ans.push_back("Bronze Medal");
            else ans.push_back(to_string(mp[score[i]]));
        }
        return ans;
    }
};