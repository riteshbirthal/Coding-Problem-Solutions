class ProductOfNumbers {
    public:
        vector<int> list, zeros;
        ProductOfNumbers() {
            list = {1};
            zeros = {0};
        }
        
        void add(int num) {
            int n = list.size();
            list[n-1]==0 ? list.push_back(num) : list.push_back(list[n-1]*num);
            num==0 ? zeros.push_back(zeros[n-1] + 1) : zeros.push_back(zeros[n-1]);
            return ;
        }
        
        int getProduct(int k) {
            int res = 0, n = list.size();
            res = zeros[n-1]==zeros[n-k-1] ? list[n-1]/max(1, list[n-k-1]) : 0;
            return res;
        }
    };
    
    /**
     * Your ProductOfNumbers object will be instantiated and called as such:
     * ProductOfNumbers* obj = new ProductOfNumbers();
     * obj->add(num);
     * int param_2 = obj->getProduct(k);
     */