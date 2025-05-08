//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        // code here
        int res = arr.size(), left = 0, right = res - 1, mid, first_term = arr[0], common_diff = arr[1]-arr[0]; 
        while(left<=right){
            mid = (left + right) / 2;
            if(first_term + mid * common_diff != arr[mid])
                res = mid, right = mid - 1;
            else
                left = mid + 1;
        }
        return first_term + res * common_diff;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends