class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans = 0, n = customers.size(), left, right, mx = 0, count = 0;
        vector<vector<int>> vec;
        for(int i = 0; i < n; i++){
            if(grumpy[i])
                vec.push_back({customers[i], i});
            else
                ans += customers[i];
        }
        if(vec.size() && minutes){
            left = 0;
            for(int i = 0; i < vec.size(); i++){
                count += vec[i][0];
                if(vec[i][1] - vec[left][1] + 1 <= minutes){
                    mx = max(mx, count);
                }else{
                    while(vec[i][1] - vec[left][1] + 1 > minutes){
                        count -= vec[left][0];
                        left++;
                    }
                    mx = max(mx, count);
                }
            }
            ans += mx;
        }
        return ans;
    }
};