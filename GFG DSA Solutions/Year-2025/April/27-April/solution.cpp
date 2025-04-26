//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string getSum(string s1, string s2){
        int n1 = s1.size(), n2 = s2.size(), carry = 0;
        string res = "";
        while(n1 && n2){
            res += '0' + (s1[n1-1]-'0' + s2[n2-1]-'0' + carry)%10;
            carry = (s1[n1-1]-'0' + s2[n2-1]-'0' + carry)/10;
            n1--, n2--;
        }
        
        while(n1){
            res += '0' + (s1[n1-1]-'0' + carry)%10;
            carry = (s1[n1-1]-'0' + carry)/10;
            n1--;
        }
        
        while(n2){
            res += '0' + (s2[n2-1]-'0' + carry)%10;
            carry = (s2[n2-1]-'0' + carry)/10;
            n2--;
        }
        
        if(carry)
            res += '1';
        while(res.size()>1 && res[res.size()-1]=='0')
            res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
    
    /*You are required to complete below function */
    string multiplyStrings(string& s1, string& s2) {
        // Your code here
        string res = "", pre = "", curr = "";
        bool sign = (s1[0]=='-')^(s2[0]=='-');
        if(s1[0]=='-'){
            reverse(s1.begin(), s1.end());
            s1.pop_back();
            reverse(s1.begin(), s1.end());
        }
        if(s2[0]=='-'){
            reverse(s2.begin(), s2.end());
            s2.pop_back();
            reverse(s2.begin(), s2.end());
        }
        int carry = 0, n1, n2 = s2.size();
        for(int i = 0; i < n2; i++){
            n1 = s1.size(), carry = 0, curr = "";
            for(int j = 0; j < n1; j++){
                curr += '0' + (carry + (s1[n1-1-j] - '0') * (s2[n2-1-i] - '0'))%10;
                carry = (carry + (s1[n1-1-j] - '0') * (s2[n2-1-i] - '0'))/10;
            }
            if(carry)
                curr += '0' + carry;
            // cout << curr << endl;
            while(curr.size()>1 && curr[curr.size()-1]=='0')
                curr.pop_back();
            reverse(curr.begin(), curr.end());
            for(int j = 0; j < i; j++)
                curr += '0';
            res = getSum(curr, pre);
            pre = res;
        }
        if(sign && res!="0")
            res = "-" + res;
        return res;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string a;
        string b;
        cin >> a >> b;
        Solution obj;
        cout << obj.multiplyStrings(a, b) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends