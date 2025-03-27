class Solution {
    public:
        bool isPrefixAndSuffix(string str1, string str2){
            int n = str1.size(), m = str2.size();
            if(n>m) return false;
            for(int i = 0; i < n; i++){
                if(str2[i]!=str1[i] || str2[m-n+i]!=str1[i])
                    return false;
            }
            return true;
        }
        int countPrefixSuffixPairs(vector<string>& words) {
            int n = words.size(), res = 0;
            for(int i = 0; i < n; i++){
                for(int j = i+1; j < n; j++){
                    if(isPrefixAndSuffix(words[i], words[j]))
                        res += 1;
                }
            }
            return res;
        }
    };