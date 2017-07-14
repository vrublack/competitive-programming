/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Tue Jun 20 16:25:15 2017 +0200
    Competition: Codeforces
    Problem id: 217A
    Problem name: Ice Skating
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <sstream>
#include <algorithm>
#include <queue>
#include <unordered_set>

#define INF INT_MAX
#define LOOP(x, n) for(int x = 0; x < n; x++)

using namespace std;

typedef long long int ll;
typedef unsigned int ui;
typedef pair<ll, ll> pr;


void dfs(int root, vector<vector<int>> &adj_list, vector<bool> &visited)
{
    visited[root] = true;

    for (int adj : adj_list[root])
        if (!visited[adj])
            dfs(adj, adj_list, visited);
}

int main()
{
    ui n;
    cin >> n;
    vector<pr> V(n, pr(0, 0));
    LOOP(i, n)cin >> V[i].first >> V[i].second;

    // there is an edge between two snow drifts if either their x or their y-coordinate is equal
    vector<vector<int>> adj_list(n, vector<int>());

    // iterate over every pair of coordinates
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (V[i].first == V[j].first || V[i].second == V[j].second)
            {
                adj_list[i].push_back(j);
                adj_list[j].push_back(i);
            }
        }
    }

    // count how many DFSs are needed to visit every snow drift
    vector<bool> visited(n, false);
    int count = 0;

    for (int root = 0; root < n; root++)
    {
        if (!visited[root])
        {
            dfs(root, adj_list, visited);
            count++;
        }
    }

    cout << count - 1;
}
