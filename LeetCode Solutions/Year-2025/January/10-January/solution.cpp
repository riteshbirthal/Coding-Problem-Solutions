class Solution {
    public:
        void buildUniversalArray(vector<int>& universalArray, string word){
            vector<int> vec(26, 0);
            for(char ch : word){
                vec[ch - 'a']++;
            }
            for(int i = 0; i < 26; i++){
                universalArray[i] = max(universalArray[i], vec[i]);
            }
            return ;
        }
    
        bool checkUniversal(vector<int>& universalArray, string word){
            vector<int> vec(26, 0);
            for(char ch : word){
                vec[ch - 'a']++;
            }
            for(int i = 0; i < 26; i++){
                if(universalArray[i]>vec[i])
                    return false;
            }
            return true;
        }
    
        vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
            vector<string> res;
            vector<int> universalArray(26, 0);
            for(string word : words2){
                buildUniversalArray(universalArray, word);
            }
            for(string word : words1){
                if(checkUniversal(universalArray, word)){
                    res.push_back(word);
                }
            }
            return res;
        }
    };