class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    map<int, int> mp;
    bool flag;
    KthLargest(int k, vector<int>& nums) {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        int n = nums.size();
        flag = k>n ? true : false;
        for(int i = 0; i < min(k, n); i++){
            if(pq.empty() || pq.top()!=nums[i])
                pq.push(nums[i]);
            mp[nums[i]]++;
        }
    }
    
    int add(int val) {
        if(flag){
            if(mp.find(val)==mp.end())
                pq.push(val);
            mp[val]++;
            flag = false;
        }else if(!pq.empty() && val>pq.top()){
            if(mp.find(val)==mp.end()) 
                pq.push(val);
            if(mp[pq.top()]==1)
                mp.erase(pq.top()), pq.pop();
            else 
                mp[pq.top()]--;
            mp[val]++;
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */