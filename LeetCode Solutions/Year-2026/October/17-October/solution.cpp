class Solution {
public:
    static bool custom_sort(int a, int b){
        int sum_a = 0, sum_b = 0, x = a, y = b;
        while(a) sum_a += a%10, a /= 10;
        while(b) sum_b += b%10, b /= 10;
        return sum_a==sum_b ? x<=y : sum_a<sum_b;
    }

    int minSwaps(vector<int>& nums) {
        vector<int> vec = nums;
        sort(vec.begin(), vec.end(), custom_sort);
        int res = 0, n = nums.size();
        unordered_map<int, int> pos;
        for(int i = 0; i < n; i++)
            pos[nums[i]] = i;
        for(int i = 0; i < n; i++){
            if(vec[i]==nums[i])
                continue;
            int x = pos[vec[i]], y = nums[i];
            pos[nums[i]] = x;
            pos[vec[i]] = i;
            nums[i] = vec[i];
            nums[x] =  y;
            res += 1;
        }
        return res;
    }
};
