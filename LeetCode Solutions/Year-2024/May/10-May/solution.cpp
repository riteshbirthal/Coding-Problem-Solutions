class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, vector<int>>> pq;
        double fraction;
        for(int i = 0; i < arr.size(); i++){
            for(int j = i+1; j < arr.size(); j++){
                fraction = double(arr[i]) / double(arr[j]);
                if(pq.size()==k){
                    if(fraction < pq.top().first){
                        pq.pop();
                        pq.push({fraction, {arr[i], arr[j]}});
                    }
                }else{
                    pq.push({fraction, {arr[i], arr[j]}});
                }
            }
        }
        return pq.top().second;
    }
};