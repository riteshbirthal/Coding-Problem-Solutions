class Solution {
    public:
        string findDifferentBinaryString(vector<string>& nums) {
            vector<int> vec;
            for(string str : nums)
                vec.push_back(stoi(str, 0, 2));
            sort(vec.begin(), vec.end());
            int n = vec.size(), resINT = n;
            for(int i = 0; i < n && resINT==n; i++){
                if(vec[i]!=i)
                    resINT = i;
            }
            string res = bitset<64>(resINT).to_string().substr(64 - n);;
            return res;
        }
    };