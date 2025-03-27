class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            int n = nums.size(), res = -1;
            vector<int> left(n+1, -1), right(n+1, -1);
            unordered_map<int, int> lt, rt;
            for(int i = 0; i < n; i++){
                lt.find(nums[i])==lt.end() ? lt[nums[i]] = 1 : lt[nums[i]]++;
                left[i+1] = (left[i]==-1) ? (lt[nums[i]]>(i+1)/2 ? nums[i] : -1) : (lt[left[i]]>(i+1)/2 ? left[i] : -1);
    
                rt.find(nums[n-1-i])==rt.end() ? rt[nums[n-1-i]] = 1 : rt[nums[n-1-i]]++;
                right[n-1-i] = (right[n-i]==-1) ? (rt[nums[n-1-i]]>(i+1)/2 ? nums[n-1-i] : -1) : (rt[right[n-i]]>(i+1)/2 ? right[n-i] : -1);
            }
            for(int i = 0; i < n && res==-1; i++){
                if(left[i+1]!=-1 && left[i+1]==right[i+1])
                    res = i;
            }
            return res;
        }
    };