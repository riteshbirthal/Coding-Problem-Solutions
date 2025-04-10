//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int MHD(int idx1, int idx2, vector<vector<int>>& houses){
        return abs(houses[idx1][0] - houses[idx2][0]) + abs(houses[idx1][1]-houses[idx2][1]);
    }
    
    int minCost(vector<vector<int>>& houses) {
        // code here
        int n = houses.size(), res = 0;
        bool breakLoop = false;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pair<int, int> pr;
        vector<bool> visited(n, false);
        pq.push({0, 0});
        while(!breakLoop){
            pr = pq.top(), pq.pop();
            if(visited[pr.second])
                continue;
            res += pr.first;
            visited[pr.second] = true;
            breakLoop = true;
            for(int i = 0; i < n; i++){
                if(!visited[i]){
                    pq.push({MHD(pr.second, i, houses), i});
                    breakLoop = false;
                }
            }
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> edges;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;

        cout << obj.minCost(edges);
        cout << "\n";
        cout << "~" << endl;
    }
}

// } Driver Code Ends
