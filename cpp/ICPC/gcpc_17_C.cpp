/**
    Author: Valentin Rublack
    Status: Wrong answer
    Last modified: Mon Jul 10 22:44:49 2017 +0200
    Competition: ICPC
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>
#include <climits>
#include <numeric>
#include <map>
#include <array>
#include <stack>
#include <iomanip>

#define FASTIN cin.sync_with_stdio(false);
#define INF INT_MAX
#define INF_LL LLONG_MAX
#define LOOP(x, n) for(int x = 0; x < n; x++)
#define READLV(a, n) vector<long long int> a(n, 0); LOOP(i, n) cin >> a[i];
#define READBV(a, n) vector<bool> a(n, 0); LOOP(i, n) {int v; cin >> v; a[i] = (bool) v; }
#define pb push_back

using namespace std;

typedef long long int ll;
typedef unsigned int ui;


int main()
{
    FASTIN

    // implementation of editorial

    int X, n, m, edge_cost;
    cin >> X >> n >> m >> edge_cost;

    vector<vector<ui>> E(m, vector<ui>());
    LOOP(i, m)
    {
        ui a, b;
        cin >> a >> b;
        E[a - 1].pb(b - 1);
        E[b - 1].pb(a - 1);
    }

    vector<int> cost(n, 0);
    vector<int> time(n, 0);
    LOOP(i, n)
    {
        ui t, p;
        cin >> t >> p;
        time[i] = t;
        cost[i] = p;
    }

    // Node x Time
    vector<vector<ll>> dp(n, vector<ll>(X + 1, INF));
    dp[0][time[0]] = cost[0];

    // process nodes in order of bfs
    queue<ui> Q;
    vector<bool> in_Q(n, false);
    vector<bool> visited(n, false);
    Q.push(0);
    in_Q[0] = true;

    while (!Q.empty())
    {
        ui v = Q.front();
        Q.pop();
        visited[v] = true;
        vector<ui> adj_vis;    // adjacent nodes that were already visited
        for (ui adj : E[v])
        {
            if (!in_Q[adj])
            {
                Q.push(adj);
                in_Q[adj] = true;
            } else if (visited[adj])
            {
                adj_vis.pb(adj);
            }
        }

        for (int t = 0; t <= X; t++)
        {
            if (t - time[v] >= 0)
            {
                if (v == 0 && t - time[v] == 0)
                    dp[v][t] = cost[v];
                else
                    dp[v][t] = cost[v] + dp[v][t - time[v]];
            }

            for (ui adj : adj_vis)
            {
                if (t - edge_cost - time[v] >= 0)
                    dp[v][t] = min(dp[v][t], cost[v] + dp[adj][t - edge_cost - time[v]]);
            }
        }
    }

    ui v = 0;
    for (int t = 0; t <= X; t++)
    {
        for (ui adj : E[v])
        {
            if (t - edge_cost - time[v] >= 0)
                dp[v][t] = min(dp[v][t], cost[v] + dp[adj][t - edge_cost - time[v]]);
        }
    }

    if (dp[0][X] >= INF)
        cout << "It is a trap.";
    else
        cout << dp[0][X];
}
