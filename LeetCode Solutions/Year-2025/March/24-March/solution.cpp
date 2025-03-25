class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            sort(meetings.begin(), meetings.end());
            int res = meetings[0][0]-1, n = meetings.size(), mx = meetings[0][1];
            for(int i = 1; i < n; i++){
                if(meetings[i][0]>mx){
                    res += meetings[i][0] - mx - 1;
                }
                mx = max(mx, meetings[i][1]);
            }
            res += days - mx;
            return res;
        }
    };