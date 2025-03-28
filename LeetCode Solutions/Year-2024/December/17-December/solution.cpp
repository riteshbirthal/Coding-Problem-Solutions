class Solution {
    public:
        string repeatLimitedString(string s, int repeatLimit) {
            vector<int> v(26, 0);
            for(char ch : s)
                v[ch-'a']++;
            priority_queue<pair<char, int>> pq;
            for(int i = 0; i < 26; i++){
                if(v[i])
                    pq.push({(char)(i+'a'), v[i]});
            }
            string ans = "";
            int count = 0, n = s.size(), flag = 1;
            pair<char, int> pr, pr1;
            for(int i = 0; i < n; i++){
                while(!pq.empty() && pq.top().second==0)
                    pq.pop(), count = 0;
                if(pq.empty() || (ans.size() && pq.size()==1 && ans[ans.size()-1]==pq.top().first && count==repeatLimit)){
                    break;
                }
                if(count==repeatLimit){
                    pr = pq.top(), pq.pop();
                    while(!pq.empty() && pq.top().second==0){
                        pq.pop();
                    }
                    if(!pq.empty()){
                        pr1 = pq.top(), pq.pop();
                        ans += pr1.first;
                        pq.push({pr1.first, pr1.second-1});
                    }else{
                        break;
                    }
                    ans.push_back(pr.first);
                    if(pr.second>1){
                        pq.push({pr.first, pr.second-1});
                        count = 1;
                    }else{
                        count = 0;
                    }
                }else{
                    pr1 = pq.top(), pq.pop();
                    ans += pr1.first;
                    pq.push({pr1.first, pr1.second - 1});
                    if(ans.size() && ans[ans.size()-1]==pq.top().first){
                        if(pr1.second>1){
                            count += 1;
                        }else{
                            count = 0;
                        }
                    }else{
                        if(pr1.second>1){
                            count = 1;
                        }else{
                            count = 0;
                        } 
                    }
                }
            }
            return ans;
        }
    };