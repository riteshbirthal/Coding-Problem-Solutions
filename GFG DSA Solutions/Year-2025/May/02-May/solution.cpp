//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// User function template for C++
class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        // code here
        int res = 0, n = arr.size(), left = 0, right = n-1, mid;
        while(left<=right){
            mid = (left + right) / 2;
            if(arr[mid-1]<arr[mid])
                left = mid + 1, res = mid;
            else
                right = mid - 1, res = mid-1;
                
        }
        return arr[res];
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        int value;

        // Read the entire line of integers
        string line;
        // cin.ignore(); // Ignore the newline after the test case input
        getline(cin, line);
        stringstream ss(line);

        // Parse integers and add them to the vector
        while (ss >> value) {
            arr.push_back(value);
        }

        Solution ob;
        auto ans = ob.findMaximum(arr);
        cout << ans << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends