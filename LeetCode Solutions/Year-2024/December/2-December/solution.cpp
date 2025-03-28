class Solution {
    public:
        void func(string s, vector<string>& words){
            string st = "";
            int n = s.size();
            for(int i = 0; i < n; i++){
                if(s[i]==' '){
                    if(st.size()) words.push_back(st);
                    st = "";
                }else{
                    st += s[i];
                }
            }
            if(st.size()) words.push_back(st);
            return ;
        }
        int isPrefixOfWord(string sentence, string searchWord) {
            vector<string> words;
            func(sentence, words);
            vector<int> vec;
            int n = words.size();
            for(int i = 0; i < n; i++){
                if(words[i].find(searchWord)==0) return i+1;
            }
            return -1;
        }
    };