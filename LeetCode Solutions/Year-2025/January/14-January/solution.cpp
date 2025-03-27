class Solution {
    public:
        vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
            int n = A.size(), count = 0;
            vector<int> res, vec(n+1, 0);
            for(int i = 0; i < n; i++){
                if(A[i]==B[i]){
                    count += 1;
                }else{
                    count += vec[A[i]]%2 + vec[B[i]]%2;
                }
                vec[A[i]]++, vec[B[i]]++;
                res.push_back(count);
            }
            return res;
        }
    };