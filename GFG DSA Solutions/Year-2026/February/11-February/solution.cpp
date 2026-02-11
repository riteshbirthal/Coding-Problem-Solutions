class Solution {
  public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        // code here
        map<int, int> mp;
        int n = heights.size(), res = 0, h, c;
        for(int i = 0; i < n; i++){
            if(mp.find(heights[i])==mp.end())
                mp[heights[i]] = cost[i];
            else
                mp[heights[i]] += cost[i];
        }
        while(mp.size()>1){
            auto left = mp.begin();
            auto right = mp.end();
            right--;
            if(left->second<=right->second){
                h = left->first, c = left->second;
                left++;
                mp.erase(h);
                res += (left->first - h) * c;
                mp[left->first] += c;
            }else{
                h = right->first, c = right->second;
                right--;
                mp.erase(h);
                res += (h - right->first) * c;
                mp[right->first] += c;
            }
        }
        return res;
    }
};
