class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0, n = logs.size();
        for(int i = 0; i < n; i++){
            if(logs[i]=="../") ans--;
            else if(logs[i]!="./") ans++;
            ans = max(0, ans);
        }
        return ans;
    }
};