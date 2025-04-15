class Solution {          //BFS approach
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {

        queue<int> q; // Using BFS so queue is involved
        vector<bool> seen(n, false);
        vector<vector<int>> adjList(n);

        // Building the adjacency list for an undirected graph
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        q.push(source);
        seen[source] = true;

        while (!q.empty()) {
            int cvertex = q.front();
            q.pop();

          //  if (cvertex == destination)
            //    return true;

            for (int i = 0; i < adjList[cvertex].size(); i++) {
                int svertex = adjList[cvertex][i];
                if (!seen[svertex]) {
                    q.push(svertex);
                    seen[svertex] = true;
                }
            }
        }

        // Final check (optional but redundant since we already return early)
        return seen[destination];
    }
};
