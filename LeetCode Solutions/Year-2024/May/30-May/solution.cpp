class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ans = 0, n = arr.size(), k = 0;
        map<int, vector<int>> mp;
        // mp[k] = {0};
        for(int i = 0; i < n; i++){
            cout << k;
            k = k^arr[i];
            cout << " -> " << k << endl;
            mp[k].push_back(i);
        }
        vector<int> vec;
        for(auto x = mp.begin(); x != mp.end(); x++){
            vec = x->second;
            for(int i = 0; i < vec.size(); i++){
            if(x->first==0) ans += max(0, vec[i]);
                for(int j = i+1; j < vec.size(); j++){
                    // cout << x->first << "   " << vec[i] << " " << vec[j] << endl;
                    ans += max(0, vec[j]-vec[i]-1);
                }
            }
        }
        return ans;
    }
};