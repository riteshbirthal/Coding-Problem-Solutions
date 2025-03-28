class Solution {
    public:
        int minimumSize(vector<int>& nums, int maxOperations) {
            int left = 1, right = *max_element(nums.begin(), nums.end()), mid, ans = right, ele, ops;
            while(left<=right){
                mid = (left + right) / 2;
                priority_queue<int> pq(nums.begin(), nums.end());
                ops = maxOperations;
                while(pq.size() && pq.top()>mid && ops){
                    ele = pq.top()-1, pq.pop();
                    pq.push(ele+1 - mid*min(ele/mid, ops));
                    ops -= min(ele/mid, ops);
                }
                if(!pq.size() || pq.top()<=mid){
                    ans = min(ans, mid);
                    right = mid-1;
                }else{
                    left = mid + 1;
                }
            }
            return ans;
        }
    };