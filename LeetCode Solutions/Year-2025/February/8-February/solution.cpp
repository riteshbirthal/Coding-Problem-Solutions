class NumberContainers {
    public:
        unordered_map<int, int> indices;
        map<int, set<int>> nums;
        NumberContainers() {
            indices.clear(), nums.clear();
        }
        
        void change(int index, int number) {
            if(indices.find(index)!=indices.end()){
                nums[indices[index]].erase(index);
            }
            indices[index] = number;
            nums[number].insert(index);
        }
        
        int find(int number) {
            if(nums.find(number)!=nums.end() && nums[number].size())
                return *nums[number].begin();
            return -1;
        }
    };