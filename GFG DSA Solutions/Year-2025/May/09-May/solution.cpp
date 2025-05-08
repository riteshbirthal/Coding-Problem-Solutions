//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    string getMax(string &s, int n, int k){
        if(n==0 || k==0)
            return s;
        string res = getMax(s, n-1, k);
        for(int i = 0; i < n-1; i++){
            char ch = s[i];
            s[i] = s[n-1];
            s[n-1] = ch;
            res = max(res, getMax(s, n-1, k-1));
            ch = s[i];
            s[i] = s[n-1];
            s[n-1] = ch;
        }
        return res;
    }
    
    // Function to find the largest number after k swaps.
    string findMaximumNum(string& s, int k) {
        // code here.
        int n = s.size();
        string res = getMax(s, n, k);
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t, k;
    string str;

    cin >> t;
    while (t--) {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends