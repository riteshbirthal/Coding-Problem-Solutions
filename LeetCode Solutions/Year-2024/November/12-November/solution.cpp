class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        int n = items.size(), mx = 0;
        vector<int> prices, beauty, ans;
        for(int i = 0; i < n; i++){
            mx = max(mx, items[i][1]);
            if(!prices.size() || prices[prices.size()-1]!=items[i][0]){
                prices.push_back(items[i][0]);
                beauty.push_back(mx);
            }else{
                beauty[beauty.size()-1] = mx;
            }
        }
        int left, right, mid;
        n = prices.size();
        for(auto q : queries){
            left = 0, right = n-1;
            while(left<=right){
                mid = (left + right) / 2;
                if(prices[mid]==q)
                    break;
                else if(prices[mid]>q)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            if(mid+1<n && prices[mid+1]<=q)
                ans.push_back(beauty[mid+1]);
            else if(prices[mid]<=q)
                ans.push_back(beauty[mid]);
            else if(mid>0 && prices[mid-1]<=q)
                ans.push_back(beauty[mid-1]);
            else
                ans.push_back(0);
        }
        return ans;
    }
};