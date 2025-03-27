class Solution {
    public:
        bool canConstruct(string s, int k) {
            vector<int> vec(26, 0);
            for(char ch : s)
                vec[ch-'a']++;
            int odd = 0, even = 0;
            for(int i = 0; i < 26; i++){
                if(vec[i]){
                    vec[i]%2 ? even += vec[i]/2, odd += 1 : even += vec[i]/2;
                }
            }
            // cout << even << " " << odd << endl;
            if(s.size()<k || odd>k) return false;
            if(odd) k -= odd-1, odd = 1;
            return 2*even+odd>=k;
        }
    };