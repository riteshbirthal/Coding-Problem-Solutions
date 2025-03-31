class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size(), mx = *max_element(nums.begin(), nums.end()), ans = 0;
        vector<int> vec(mx+1, 0), vec2(mx+1, 0);
        for(int i = 0; i < n; i++)
            vec[nums[i]]++;
        vec2[0] = vec[0];
        for(int i = 1; i <= mx; i++)
            vec2[i] = vec[i] + vec2[i-1];
        // for(int i = 0; i <= mx; i++)
        //     cout << i <<  " " << vec[i] << endl;
        int l = 0, r = mx, mid, count;
        while(l<=r){
            mid = (l + r) / 2;
            count = 0;
            for(int i = 0; i <= mx; i++){
                count += (vec2[min(mx, i+mid)] - vec2[i]) * vec[i];
                count += (vec[i] * (vec[i] - 1)) / 2;
            }
            // cout << mid << " " << count << endl;
            if(count >= k){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        ans = l;
        return ans;
    }
};