class Solution {
    public:
        int nth;
        vector<char> letters;
        string func(string st, int n){
            if(st.size()==n || nth==0){
                nth--;
                return nth==0 ? st : "";
            }
            string res = "";
            for(char ch : letters){
                if(st.size()==0 || st[st.size()-1]!=ch){
                    res = func(st+ch, n);
                    if(res.size())
                        return res;
                }
            }
            return res;
        }
        string getHappyString(int n, int k) {
            nth = k;
            letters = {'a', 'b', 'c'};
            string res = func("", n);
            return res;
        }
    };