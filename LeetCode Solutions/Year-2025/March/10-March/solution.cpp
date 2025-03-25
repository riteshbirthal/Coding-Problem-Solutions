class Solution {
    public:
        bool isVowel(int x){
            return x==0 || x==4 || x==8 || x==14 || x==20;
        }
    
        long long countWithMaxK(string word, int k){
            long long res = 0;
            int n = word.size(), start = 0, end = 0, consonants = 0;
            unordered_map<char, int> vowels;
            while(end<n){
                if(isVowel(word[end]-'a'))
                    vowels.find(word[end])==vowels.end() ? vowels[word[end]] = 1 : vowels[word[end]]++;
                else
                    consonants++;
                while(vowels.size()==5 && consonants>=k){
                    if(isVowel(word[start]-'a'))
                        vowels[word[start]]==1 ? vowels.erase(word[start]) : vowels[word[start]]--;
                    else
                        consonants--;
                    start++;
                    res += n-end;
                }
                end++;
            }
            return res;
        }
    
        long long countOfSubstrings(string word, int k) {
            return countWithMaxK(word, k) - countWithMaxK(word, k+1);
        }
    };