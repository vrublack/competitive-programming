/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Tue Jul 4 17:51:44 2017 +0200
    Competition: Codeforces
    Problem id: 429A
    Problem name: Xor-tree
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
#define LOOP(x, n) for(int x = 0; x < n; x++)
#define READLV(a, n) vector<long long int> a(n, 0); LOOP(i, n) cin >> a[i];
#define READBV(a, n) vector<bool> a(n, 0); LOOP(i, n) {int v; cin >> v; a[i] = (bool) v; }
#define pb push_back

using namespace std;

typedef long long int ll;


void xor_tree(vector<vector<int>> &E, int root, int parent, vector<bool> &init, vector<bool> &goal, bool flip_even,
              bool flip_odd,
              int depth, vector<int> &solution)
{
    bool on = init[root];
    if (depth % 2 == 0 && flip_even || depth % 2 == 1 && flip_odd)
        on = !on;

    if (on != goal[root])
    {
        solution.pb(root);
        if (depth % 2 == 0)
            flip_even = !flip_even;
        else
            flip_odd = !flip_odd;
    }

    for (int adj : E[root])
    {
        if (adj != parent)
            xor_tree(E, adj, root, init, goal, flip_even, flip_odd, depth + 1, solution);
    }
}


int main()
{
    FASTIN

    int n;
    cin >> n;
    vector<vector<int>> E(n, vector<int>());
    LOOP(i, n - 1)
    {
        int u, v;
        cin >> u >> v;
        E[u - 1].pb(v - 1);
        E[v - 1].pb(u - 1);
    }
    READBV(init, n)
    READBV(goal, n)

    vector<int> solution;
    xor_tree(E, 0, -1, init, goal, false, false, 0, solution);

    cout << solution.size() << endl;
    LOOP(i, solution.size())
    {
        cout << solution[i] + 1 << endl;
    }
}
