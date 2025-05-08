//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int findSubString(string& str) {
        // code here
        int n = str.size(), res = n, left = 0, right = 0, dist_ele = 0;
        unordered_map<char, int> u;
        for(char ch : str)
            u[ch]++;
        dist_ele = u.size();
        u.clear();
        while(right<n){
            u.find(str[right])==u.end() ? u[str[right]] = 1 : u[str[right]]++;
            while(u.size()==dist_ele){
                u[str[left]]==1 ? u.erase(str[left]) : u[str[left]]--;
                res = min(res, right-left+1);
                left++;
            }
            right++;
        }
        return res;
    }
};




//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends