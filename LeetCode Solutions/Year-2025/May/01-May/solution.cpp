class Solution {
public:
    bool isPossible(vector<int>& tasks, vector<int>& workers, int pills, int strength, int k){
        int m = workers.size();
        vector<int> work(m, 0);
        set<int> available;
        for(int i = 0; i < m; i++)
            available.insert(i);
        for(int i = k-1, j = m-1; i >= 0; ){
            if(i>=0 && j<0){
                return false;
            }
            if(work[j]){
                j--;
                continue;
            }else if(tasks[i]<=workers[j]){
                i--, j--;
                continue;
            }else if(!pills){
                return false;
            }
            int left = 0, right = j, mid, idx = -1;
            while(left<=right){
                mid = (left + right) / 2;
                if(workers[mid]+strength>=tasks[i]){
                    idx = mid;
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
            if (idx == -1 || idx > j || workers[idx] + strength < tasks[i]){
                return false;
            }
            auto it = available.lower_bound(idx);
            if (it != available.end() && *it <= j) {
                idx = *it;
                available.erase(it);
                work[idx] = 1; 
                i--, pills--;
            } else {
                return false;
            }
        }
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size(), m = workers.size();
        int res = 0, pi = pills, left = 0, right = n, mid;
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        while(left<=right){
            mid = (left + right) / 2;
            if(isPossible(tasks, workers, pills, strength, mid)){
                res = mid;
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return res;
    }
};