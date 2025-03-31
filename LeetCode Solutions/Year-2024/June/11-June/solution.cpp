class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> vec(1001, 0), vec1(1001, 0), ans;
        for(int i = 0; i < arr2.size(); i++)
            vec1[arr2[i]]++;
        for(int i = 0; i < arr1.size(); i++)
            if(vec1[arr1[i]])
                vec[arr1[i]]++;
            else
                vec[arr1[i]]--;
        for(int i = 0; i < arr2.size(); i++)
            while(vec[arr2[i]])
                ans.push_back(arr2[i]), vec[arr2[i]]--;
        for(int i = 0; i < vec.size(); i++)
            while(vec[i]++) ans.push_back(i);
        return ans;
    }
};