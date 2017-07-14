/**
    Author: Valentin Rublack
    Status: Own implementation of Ford-Fulkerson algorithm to compute the max flow of a graph
    Last modified: Thu Jun 29 12:10:18 2017 +0200
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <sstream>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <stack>
#include <map>
#include <list>
#include <climits>
#include <cstring>

#define INF INT_MAX
#define LOOP(x, n) for(ll x = 0; x < n; x++)
#define IT(x, l) for (auto x = l.begin(); x != l.end(); x++)

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pr;
typedef pair<long, int> ii;

ll mod = 1000000007;


/* Returns true if there is a path from source 's' to sink 't' in
  residual graph. Also fills parent[] to store the path */
bool bfs(vector<vector<int>> &rGraph, int s, int t, int parent[])
{
    unsigned int V = rGraph.size();

    // Create a visited array and mark all vertices as not visited
    bool visited[V];
    memset(visited, 0, sizeof(visited));

    // Create a queue, enqueue source vertex and mark source vertex
    // as visited
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    // Standard BFS Loop
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    // If we reached sink in BFS starting from source, then return
    // true, else false
    return visited[t];
}

// Returns tne maximum flow from s to t in the given graph
int ford_fulkerson(vector<vector<int>> &graph, int s, int t)
{
    unsigned int V = graph.size();
    int u, v;

    // Create a residual graph and fill the residual graph with
    // given capacities in the original graph as residual capacities
    // in residual graph
    vector<vector<int>> rGraph(V, vector<int>(V, 0)); // Residual graph where rGraph[i][j] indicates
    // residual capacity of edge from i to j (if there
    // is an edge. If rGraph[i][j] is 0, then there is not)
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];

    int parent[V];  // This array is filled by BFS and to store path

    int max_flow = 0;  // There is no flow initially

    // Augment the flow while tere is path from source to sink
    while (bfs(rGraph, s, t, parent))
    {
        // Find minimum residual capacity of the edhes along the
        // path filled by BFS. Or we can say find the maximum flow
        // through the path found.
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        // update residual capacities of the edges and reverse edges
        // along the path
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        // Add path flow to overall flow
        max_flow += path_flow;
    }

    // Return the overall flow
    return max_flow;
}


int main()
{

}
