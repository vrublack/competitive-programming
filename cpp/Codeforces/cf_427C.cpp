/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Thu Jun 22 21:47:37 2017 +0200
    Competition: Codeforces
    Problem id: 427C
    Problem name: Checkposts
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <sstream>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <map>
#include <unordered_map>

#define INF INT_MAX
#define LOOP(x, n) for(int x = 0; x < n; x++)

using namespace std;

typedef long long int ll;
typedef unsigned int ui;
typedef pair<ll, ll> pr;


void dfs(ui root, vector<vector<ui>> &adj_list, vector<bool> &visited, unordered_set<ui> &newly_visited)
{
    for (ui adj : adj_list[root])
    {
        if (!visited[adj] && newly_visited.find(adj) == newly_visited.end())
        {
            newly_visited.insert(adj);
            dfs(adj, adj_list, visited, newly_visited);
        }
    }
}

int main()
{
    cin.sync_with_stdio(false);

    ui n;
    cin >> n;
    vector<pr> junctions(n, pr());
    // node -> cost
    vector<ll> cost(n, 0);
    LOOP(i, n)
    {
        cin >> junctions[i].first;
        junctions[i].second = i;
        cost[i] = junctions[i].first;
    }
    // sort by cost
    sort(junctions.begin(), junctions.end());
    ui m;
    cin >> m;
    vector<vector<ui>> adj_list(n, vector<ui>());
    vector<vector<ui>> adj_list_r(n, vector<ui>()); // reverse
    LOOP(i, m)
    {
        ui from, to;
        cin >> from >> to;
        from--;
        to--;

        adj_list[from].push_back(to);
        adj_list_r[to].push_back(from);
    }

    ll result_cost = 0;
    vector<bool> reached(n, false);
    ll poss = 1;
    LOOP(i, n)
    {
        ll poss_i = 0;
        ui root = junctions[i].second;

        if (reached[root])
            continue;
        else
            result_cost += junctions[i].first;

        unordered_set<ui> newly_visited;
        newly_visited.insert(root);
        dfs(root, adj_list, reached, newly_visited);
        unordered_set<ui> newly_visited_r;
        newly_visited_r.insert(root);
        dfs(root, adj_list_r, reached, newly_visited_r);

        // add the intersection between newly_visited and newly_visited_r to visited
        for (ui node : newly_visited)
        {
            if (newly_visited_r.find(node) != newly_visited_r.end())
            {
                reached[node] = true;

                // we could have also chosen this one since the cost is equal and it reaches all the junctions that root reaches
                if (cost[node] == junctions[i].first)  // note that this also includes root once
                    poss_i++;
            }
        }

        poss *= poss_i;
        poss %= 1000000007;
    }

    cout << result_cost << " " << poss;
}
