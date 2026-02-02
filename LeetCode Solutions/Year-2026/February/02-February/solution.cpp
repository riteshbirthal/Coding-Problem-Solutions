class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        long long res = LONG_LONG_MAX, temp = 0, ele;
        int n = nums.size(), max_heap_size = 0;
        map<long long, int> min_heap, max_heap;
        for(int i = 1; i < n; i++){
            max_heap_size += 1;
            max_heap[nums[i]]++;
            temp += nums[i];
            while(max_heap_size<k-1 && min_heap.size()){
                ele = min_heap.begin()->first;
                min_heap[ele]==1 ? min_heap.erase(ele) : min_heap[ele]--;
                max_heap[ele]++;
                max_heap_size++;
                temp += ele;
            }
            while(min_heap.size() && min_heap.begin()->first < max_heap.rbegin()->first){
                ele = min_heap.begin()->first;
                min_heap[ele]==1 ? min_heap.erase(ele) : min_heap[ele]--;
                max_heap[ele]++;
                temp += ele;
                ele = max_heap.rbegin()->first;
                max_heap[ele]==1 ? max_heap.erase(ele) : max_heap[ele]--;
                min_heap[ele]++;
                temp -= ele;
            }
            while(max_heap_size>=k){
                ele = max_heap.rbegin()->first;
                min_heap[ele]++;
                max_heap[ele]==1 ? max_heap.erase(ele) : max_heap[ele]--;
                temp -= ele;
                max_heap_size--;
            }
            if(max_heap_size==k-1)
                res = min(res, temp);
            if(i>dist){
                if(min_heap.find(nums[i-dist])!=min_heap.end()){
                    min_heap[nums[i-dist]]==1 ? min_heap.erase(nums[i-dist]) : min_heap[nums[i-dist]]--;
                }else{
                    max_heap[nums[i-dist]]==1 ? max_heap.erase(nums[i-dist]) : max_heap[nums[i-dist]]--;
                    temp -= nums[i-dist];
                    max_heap_size--;
                }
            }
        }
        return res + nums[0];
    }
};
