class Solution {
    public:
        long long pickGifts(vector<int>& gifts, int k) {
            priority_queue<int> pq(gifts.begin(), gifts.end());
            long long ans = 0, ele;
            while(k--){
                ele = pq.top(), pq.pop();
                pq.push((int)sqrt(ele));
            }
            while(pq.size()){
                ele = pq.top(), pq.pop();
                ans += ele;
            }
            return ans;
        }
    };