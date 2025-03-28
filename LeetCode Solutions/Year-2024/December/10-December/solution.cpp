class Solution {
    public:
        int maximumLength(string s) {
            int n = s.size(), left = 1, right = n-2, mid, ans = -1, count, flag;
            vector<int> vec(26, 0);
            map<char, int> mp;
            while(left<=right){
                mid = (left + right) / 2;
                for(int i = 0; i < mid-1; i++){
                    vec[s[i]-'a']++;
                }
                for(int i = mid-1; i < n; i++){
                    vec[s[i]-'a']++;
                    count = 0;
                    for(int j = 0; j < 26; j++){
                        if(vec[j]) count++;
                    }
                    if(count==1)
                        mp[s[i]]++;
                    vec[s[i-mid+1]-'a']--;
                }
                flag = false;
                for(auto x = mp.begin(); x != mp.end(); x++){
                    if(x->second > 2){
                        ans = max(ans, mid);
                        flag = true;
                    }
                }
                mp.clear();
                for(int i = 0; i < 26; i++)
                    vec[i] = 0;
                if(flag) left = mid + 1;
                else right = mid - 1;
            }
            return ans;
        }
    };