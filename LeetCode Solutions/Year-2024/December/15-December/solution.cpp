class Solution {
    public:
        double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
            double passRatio, ans = 0, totalPassRatio = 0, changeInPassRatio;
            priority_queue<vector<double>> pq;
            int n = classes.size();
            for(int i = 0; i < n; i++){
                passRatio = (double)classes[i][0] / (double)classes[i][1];
                changeInPassRatio = (double)(classes[i][0] + 1)/ (double)(classes[i][1] + 1) - passRatio;
                pq.push({changeInPassRatio, passRatio, (double)classes[i][0] + 1, (double)classes[i][1] + 1});
            }
            vector<double> v;
            while(extraStudents--){
                v = pq.top(), pq.pop();
                passRatio = v[0] + v[1];
                changeInPassRatio = (double)(v[2] + 1) / (double)(v[3] + 1) - passRatio;
                pq.push({changeInPassRatio, passRatio, v[2] + 1, v[3] + 1});
            }
            while(pq.size()){
                totalPassRatio += pq.top()[1];
                pq.pop();
            }
            ans = totalPassRatio/(double)n;
            return ans;
        }
    };