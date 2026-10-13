class Solution {
public:
    static bool sort_func(int a, int b){
        return abs(a)<abs(b);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), sort_func);
        int left = 0, right = nums.size()-1;
        bool isRight = true;
        long long res = 0;
        while(left<=right){
            if(isRight)
                res += nums[right]*nums[right], right--;
            else
                res -= nums[left]*nums[left], left++;
            isRight = !isRight;
        }
        return res;
    }
};
