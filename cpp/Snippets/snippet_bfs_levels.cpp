/**
    Author: Valentin Rublack
    Status: BFS (breadth-first search) including levels
    Last modified: Thu Jun 29 12:29:42 2017 +0200
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>
#include <climits>

#define INF INT_MAX
#define LOOP(x, n) for(int x = 0; x < n; x++)

using namespace std;

typedef long long int ll;
typedef unsigned int uint;


/**
 * Does bfs and also computes the levels (amount of stepts until a certain node)
 * @param adj_list Adjacency list of the graph
 * @param levels Declare as such: vector<uint> turns_alice(n, INF)
 * @param root Where the bfs should start
 */
void bfs_levels(vector<vector<uint>> &adj_list, vector<uint> &levels, uint root)
{
    queue<uint> q;
    q.push(root);
    levels[root] = 0;

    while (!q.empty())
    {
        uint u = q.front();
        q.pop();

        for (uint adj : adj_list[u])
        {
            if (levels[adj] == INF)
            {
                levels[adj] = levels[u] + 1;
                q.push(adj);
            }
        }
    }

}

int main()
{

}
