class Solution {
    public:
        bool isVowel(char ch){
            return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
        }
        vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
            int n = words.size();
            vector<int> vec(n+1, 0), res;
            for(int i = 0; i < n; i++){
                vec[i+1] = vec[i] + int(isVowel(words[i][0]) && isVowel(words[i][words[i].size()-1]));
            }
            for(auto q : queries){
                res.push_back(vec[q[1]+1] - vec[q[0]]);
            }
            return res;
        }
    };