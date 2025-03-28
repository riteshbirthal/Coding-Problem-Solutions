// User function Template for C++

class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals, vector<int> &newInterval) {
        // code here
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> vec;
        vec.push_back(intervals[0]);
        for(int i = 1; i <intervals.size(); i++){
            if(vec[vec.size()-1][1] >= intervals[i][0]) vec[vec.size()-1][1] = max(vec[vec.size()-1][1], intervals[i][1]);
            else vec.push_back(intervals[i]);
        }
        return vec;
    }
};