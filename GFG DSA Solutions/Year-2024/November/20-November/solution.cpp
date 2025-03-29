class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        // Your code goes here.
        unordered_map<int, int> u;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<int> vec;
        for(int x : arr){
            if(u.find(x)==u.end()) u[x] = 1;
            else u[x]++;
            if(u[x]>n/3 && ((vec.size() && vec[vec.size()-1]!=x) || !vec.size())) 
                vec.push_back(x);
            
        }
        return vec;
    }
};