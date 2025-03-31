class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string, int> mp;
        int n = arr.size();
        for(int i = 0; i < n; i++)
            mp[arr[i]]++;
        for(int i = 0; i < n; i++){
            if(k==1 && mp[arr[i]]==1)
                return arr[i];
            else if(mp[arr[i]]==1)
                k--;
        }
        return "";
    }
};