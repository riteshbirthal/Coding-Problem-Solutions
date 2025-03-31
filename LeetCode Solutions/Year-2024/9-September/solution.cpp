/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> vec(m, vector<int>(n, -1));
        int row_start = 0, row_end = m, column_start = 0, column_end = n, direction = 0;
        while(head){
            switch (direction%4){
                case 0:
                    for(int i = column_start; i < column_end && head; i++){
                        vec[row_start][i] = head->val;
                        head = head->next;
                    }
                    break;

                case 1:
                    for(int i = row_start+1; i < row_end && head; i++){
                        vec[i][column_end-1] = head->val;
                        head = head->next;
                    }
                    break;

                case 2:
                    for(int i = column_end-2; i >= column_start && head; i--){
                        vec[row_end-1][i] = head->val;
                        head = head->next;
                    }
                    break;

                default:
                    for(int i = row_end-2; i > row_start && head; i--){
                        vec[i][column_start] = head->val;
                        head = head->next;
                    }
                    break;
            }
            direction++;
            if(direction%4==0)
                row_start++, row_end--, column_start++, column_end--;
        }
        return vec;
    }
};