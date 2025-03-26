class Solution {
    public:
        string getLCS(string& s1, string& s2, int n, int m, string dp[][1001]){
            if(n==s1.size() || m==s2.size())
                return "";
            if(dp[n][m]!="-1")
                return dp[n][m];
            if(s1[n]==s2[m]){
                return s1[n] + getLCS(s1, s2, n+1, m+1, dp);
            }
            string r1, r2;
            r1 = getLCS(s1, s2, n+1, m, dp);
            r2 = getLCS(s1, s2, n, m+1, dp);
            return dp[n][m] = r1.size()>r2.size() ? r1 :  r2;
        }
    
        string shortestCommonSupersequence(string str1, string str2) {
            int n = str1.size(), m = str2.size();
            static string dp[1001][1001];
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    dp[i][j] = "-1";
            string LCS = getLCS(str1, str2, 0, 0, dp), res = "";
            int idx1 = 0, idx2 = 0, idx3 = 0, k = LCS.size();
            while(idx1 < n || idx2 < m){
                if(idx1<n && idx2<m && idx3<k && str1[idx1]==str2[idx2] && str2[idx2]==LCS[idx3]){
                    res += LCS[idx3];
                    idx1++, idx2++, idx3++;
                }else if(idx3==k){
                    idx1<n ? res += str1[idx1++] : "";
                    idx2<m ? res += str2[idx2++] : "";
                }else if(idx1<n && str1[idx1]!=LCS[idx3]){
                    res += str1[idx1++];
                }else{
                    res += str2[idx2++];
                }
            }
            return res;
        }
    };