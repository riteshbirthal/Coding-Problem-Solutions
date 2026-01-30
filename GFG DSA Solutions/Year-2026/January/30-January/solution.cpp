class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        queue<int> q1, q2;
        int k = q.size()/2;
        for(int i = 0; i < k; i++)
            q1.push(q.front()), q.pop();
        for(int i = 0; i < k; i++)
            q2.push(q.front()), q.pop();
        while(q1.size())
            q.push(q1.front()), q.push(q2.front()), q1.pop(), q2.pop();
    }
};
