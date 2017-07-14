/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Tue Jun 6 23:51:45 2017 +0200
    Competition: Codeforces
    Problem id: 813C
    Problem name: The Tag Game
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>

#define INF INT_MAX
#define LOOP(x, n) for(int x = 0; x < n; x++)

using namespace std;

typedef long long int ll;
typedef unsigned int uint;


void bfs_levels(vector<vector<uint>> &adj_list, vector<uint> &levels, uint start)
{
    queue<uint> q;
    q.push(start);
    levels[start] = 0;

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
    uint n, x;
    cin >> n >> x;
    x--;    // we treat vertices as zero-based
    vector<vector<uint>> adj_list(n, vector<uint>());
    for (int i = 0; i < n - 1; i++)
    {
        uint a, b;
        cin >> a >> b;
        adj_list[a - 1].push_back(b - 1);
        adj_list[b - 1].push_back(a - 1);
    }

    // bfs starting from root
    vector<uint> turns_alice(n, INF);   // how many turns Alice needs to go to vertex i
    bfs_levels(adj_list, turns_alice, 0);

    // bfs starting from x
    vector<uint> turns_bob(n, INF);
    queue<uint> q;
    q.push(x);
    turns_bob[x] = 0;

    uint max_turns = 0;

    while (!q.empty())
    {
        uint u = q.front();
        q.pop();

        // Bob runs away from Alice, and Bob can't pass vertices that Alice can visit before
        if (turns_alice[u] <= turns_bob[u])
            continue;

        max_turns = max(max_turns, turns_alice[u]);

        for (uint adj : adj_list[u])
        {
            if (turns_bob[adj] == INF)
            {
                turns_bob[adj] = turns_bob[u] + 1;
                q.push(adj);
            }
        }
    }

    // multiply by two because we also count Bobs turns
    cout << max_turns * 2;


    return 0;
}
