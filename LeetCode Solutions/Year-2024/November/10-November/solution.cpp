class Solution {
public:
    void add_bit(int n, vector<int>& vec){
        for(int i = 0; i < 32; i++){
            if(n & (1<<i)) vec[i]++;
        }
        return ;
    }

    void remove_bit(int n, vector<int>& vec){
        for(int i = 0; i < 32; i++){
            if(n & (1<<i)) vec[i]--;
        }
        return ;
    }

    int calculate_num(vector<int>& vec){
        int ans = 0;
        for(int i = 0; i < 32; i++){
            if(vec[i])
                ans += (1<<i);
        }
        return ans;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans = INT_MAX, n = nums.size(), left = 1, right = n, mid, flag, num;
        vector<int> vec(32, 0), temp(32, 0);
        while(left<=right){
            flag = 0;
            mid = (left + right) / 2;
            for(int i = 0; i < mid-1; i++){
                add_bit(nums[i], vec);
            }
            for(int i = mid-1; i < n && !flag; i++){
                add_bit(nums[i], vec);
                num = calculate_num(vec);
                if(num>=k) flag = 1;
                remove_bit(nums[i-mid+1], vec);
            }
            if(flag) ans = min(ans, mid), right = mid - 1;
            else left = mid + 1;
            vec = temp;
        }
        return ans==INT_MAX ? -1 : ans;
    }
};