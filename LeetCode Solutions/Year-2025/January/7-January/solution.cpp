class Solution {
    public:
        vector<string> stringMatching(vector<string>& words) {
            vector<string> res;
            for(string word : words){
                for(string w : words){
                    if(w != word && w.find(word)!=string::npos){
                        res.push_back(word);
                        break;
                    }
                }
            }
            return res;
        }
    };