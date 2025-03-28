class Solution {
    public:
        bool checkSubsequence(string &s1, string &s2, int n1, int n2){
            if(n2<0) return true;
            if(n1<0) return false;
            if(s1[n1]==s2[n2] || s1[n1]==(s2[n2]-'a'+25)%26+'a'){
                return checkSubsequence(s1, s2, n1-1, n2-1);
            }
            return checkSubsequence(s1, s2, n1-1, n2);
        }
    
        bool canMakeSubsequence(string str1, string str2) {
            int n1 = str1.size(), n2 = str2.size();
            if(n1<n2) return false;
            return checkSubsequence(str1, str2, n1-1, n2-1);
        }
    };