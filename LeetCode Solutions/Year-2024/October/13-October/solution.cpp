class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> vec = {-100000, 100000};
        vector<vector<int>> v;
        int n = nums.size(), l = 0, r = 0, k = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < nums[i].size(); j++){
                v.push_back({nums[i][j], i});
            }
        }
        sort(v.begin(), v.end());
        unordered_map<int, int> u;
        n = v.size();
        while(r<n){
            u[v[r][1]]++;
            while(u.size()==k){
                if(vec[1]-vec[0]>v[r][0]-v[l][0]){
                    vec = {v[l][0], v[r][0]};
                }
                if(u[v[l][1]]==1)
                    u.erase(v[l][1]);
                else 
                    u[v[l][1]]--;
                l++;
            }
            r++;
        }
        while(u.size()==k){
            if(vec[1]-vec[0]>v[r][0]-v[l][0]){
                vec = {v[l][0], v[r][0]};
            }
            if(u[v[l][1]]==1)
                u.erase(v[l][1]);
            else 
                u[v[l][1]]--;
            l++;
        }
        return vec;
    }
};