class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int k{0}, count{0}, num1{0}, num2{0};
        for (int i = 0; i < nums.size(); i++)
            k ^= nums[i];
        while (k % 2 == 0)
            k /= 2, count++;
        for (int i = 0; i < nums.size(); i++)
            if ((long long)nums[i] & (long long)pow(2, count))
                num1 ^= nums[i];
            else
                num2 ^= nums[i];
        return {num1, num2};
    }
};