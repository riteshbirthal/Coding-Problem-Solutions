class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans = INT_MIN, n = arrays.size(), mx1 = INT_MIN, mx2 = INT_MIN, mn1 = INT_MAX, mn2 = INT_MAX;
        for(int i = 0; i < n; i++){
            if(arrays[i][0]<=mn1){
                mn2 = mn1;
                mn1 = arrays[i][0];
            }else if(arrays[i][0]>mn1 && arrays[i][0]<=mn2){
                mn2 = arrays[i][0];
            }
            if(arrays[i][arrays[i].size()-1]>=mx1){
                mx2 = mx1;
                mx1 = arrays[i][arrays[i].size()-1];
            }else if(arrays[i][arrays[i].size()-1]<mx1 && arrays[i][arrays[i].size()-1]>=mx2){
                mx2 = arrays[i][arrays[i].size()-1];
            }
        }
        for(int i = 0; i < n; i++){
            if(mn1==arrays[i][0]){
                ans = max(ans, abs(arrays[i][arrays[i].size()-1] - mn2));
            }else{
                ans = max(ans, abs(arrays[i][arrays[i].size()-1] - mn1));
            }
            if(mx1==arrays[i][arrays[i].size()-1]){
                ans = max(ans, abs(mx2 - arrays[i][0]));
            }else{
                ans = max(ans, abs(mx1 - arrays[i][0]));
            }
        }
        return ans;
    }
};