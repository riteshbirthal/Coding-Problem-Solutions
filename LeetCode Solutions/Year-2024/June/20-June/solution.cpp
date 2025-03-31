class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size(), left, right, mid, count, prev, ans = 1;
        sort(position.begin(), position.end());
        left = 2, right = position[n-1] - position[0];
        while(left <= right){
            mid = (left + right) / 2;
            count = 1, prev = position[0];
            for(int i = 1; i < n; i++){
                if(position[i]-prev>=mid){
                    prev = position[i];
                    count++;
                }
            }
            if(count>=m){
                ans = max(ans, mid);
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return ans;
    }
};