class Solution {
public:
    unordered_map<int, vector<int>> adjList;
    unordered_map<int, int> inDegree, outDegree;
    vector<vector<int>> result;
    stack<int> pathStack;

    void dfs(int node) {
        while (outDegree[node]) {
            outDegree[node]--;
            int nextNode = adjList[node][outDegree[node]];
            dfs(nextNode);
        }
        pathStack.push(node);
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& edges) {
        unordered_set<int> uniqueNodes;
        for (auto &edge : edges) {
            int startNode = edge[0], endNode = edge[1];
            adjList[startNode].push_back(endNode);
            uniqueNodes.insert(startNode);
            uniqueNodes.insert(endNode);
            outDegree[startNode]++;
            inDegree[endNode]++;
        }

        int startingNode = *uniqueNodes.begin();
        for (auto &node : uniqueNodes) {
            if (inDegree[node] < outDegree[node]) {
                startingNode = node;
            }
        }

        dfs(startingNode);

        int fromNode = pathStack.top(); pathStack.pop();
        while (!pathStack.empty()) {
            int toNode = pathStack.top(); pathStack.pop();
            result.push_back({fromNode, toNode});
            fromNode = toNode;
        }
        return result;
    }
};