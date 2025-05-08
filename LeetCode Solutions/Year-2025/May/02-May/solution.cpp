class Solution {
public:
    pair<int, char> findNextIdxChar(string& dominoes, int curr_idx, int n){
        char ch = '.';
        int idx = curr_idx;
        for(int j = curr_idx+1; j < n && ch=='.'; j++, idx++){
            ch = dominoes[j];
        }
        return {idx, ch};
    }

    string pushDominoes(string dominoes) {
        int n = dominoes.size(), flag;
        for(int i = 0; i < n; i++){
            if(dominoes[i]!='.' || (i && i+1<n && dominoes[i-1]=='R' && dominoes[i+1]=='L'))
                continue;
            //  case 5/6
            if(i==0){
                pair<int, char> pr = findNextIdxChar(dominoes, i, n);
                if(pr.second=='L'){
                    for(int j = i; j <= pr.first; j++)
                        dominoes[j] = 'L';
                }
                i = pr.first;
                continue;
            }
            // case 3/4/7
            if(dominoes[i-1]=='L'){
                pair<int, char> pr = findNextIdxChar(dominoes, i, n);
                if(pr.second=='L'){
                    for(int j = i; j <= pr.first; j++)
                        dominoes[j] = 'L';
                }
                i = pr.first;
                continue;
            }
            // case 1/2/8
            if(dominoes[i-1]=='R'){
                pair<int, char> pr = findNextIdxChar(dominoes, i, n);
                if(pr.second=='.' || pr.second=='R'){
                    for(int j = i; j <= pr.first; j++)
                        dominoes[j] = 'R';
                }else if(pr.second=='L'){
                    for(int j = i, k = pr.first-1; j < k; j++, k--){
                        dominoes[j] = 'R', dominoes[k] = 'L';
                    }
                }
                i = pr.first;
            }
        }
        return dominoes;
    }
};
// case 1: R.....L
// case 2: R.....R
// case 3: L.....L
// case 4: L.....R
// case 5: ......L
// case 6: ......R
// case 7: L......
// case 8: R......