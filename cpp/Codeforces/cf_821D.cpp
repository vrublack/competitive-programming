/**
    Author: Valentin Rublack
    Status: Still implementing
    Last modified: Thu Jul 13 13:02:35 2017 +0200
    Competition: Codeforces
    Problem id: 821D
    Problem name: Okabe and City
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <climits>
#include <array>
#include <unordered_set>

#define FASTIN cin.sync_with_stdio(false);
#define INF INT_MAX
#define INF_LL LLONG_MAX
#define LOOP(x, n) for(int x = 0; x < n; x++)
#define READLV(a, n) vector<long long int> a(n, 0); LOOP(i, n) cin >> a[i];
#define READBV(a, n) vector<bool> a(n, 0); LOOP(i, n) {int v; cin >> v; a[i] = (bool) v; }
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<long, int> ii;

const ll mod = 1000000007;


struct Edge
{
    ll dest;
    ll weight;


    Edge(ll dest, ll weight) : dest(dest), weight(weight)
    {}
};

struct EdgeEqual
{
    bool operator()(const Edge &a, const Edge &b)
    {
        return a.dest == b.dest;
    }
};


vector<ll> dijkstra(ll root, vector<unordered_set<Edge, std::hash<Edge>, EdgeEqual>> &adjList)
{
    ll V = adjList.size();

    vector<ii> Q;
    Q.push_back(ii(0, root));

    // distance from root
    vector<ll> dist(V, INF_LL);
    dist[root] = 0;

    make_heap(Q.begin(), Q.end(), greater<ii>());

    while (!Q.empty())
    {
        ii pair = Q[0];
        ll u = pair.second;
        if (pair.first != dist[u])
        {
            pop_heap(Q.begin(), Q.end(), greater<ii>());
            Q.pop_back();
            // this can happen due to the decrease-key fix
            continue;
        }
        pop_heap(Q.begin(), Q.end(), greater<ii>());
        Q.pop_back();

        for (Edge adj : adjList[u])
        {
            if (adj.weight < dist[adj.dest] - dist[u])
            {
                dist[adj.dest] = dist[u] + adj.weight;
                // decrease-key is not supported by the heap algorithms, so just throw it in there even though it's already in the queue
                Q.push_back(ii(dist[u] + adj.weight, adj.dest));
                push_heap(Q.begin(), Q.end(), greater<ii>());
            }
        }
    }

    return dist;
}


int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<pii> lit(k, pii());
    array<vector<int>, 10002> lit_rows;
    array<vector<int>, 10002> lit_cols;
    LOOP(i, k)
    {
        cin >> lit[i].first >> lit[i].second;
        lit_rows[lit[i].first].pb(i);
        lit_cols[lit[i].second].pb(i);
    }

    // Build a graph. An edge between two initially lit cells exists if they're either adjacent (except diagonally) or you can
    // get to them by lighting a row or column. You can always achieve this if one of their coordinates is not further away than two.

    // add dummy lit cell one below the bottom right cell to ensure the bottom right cell is always lit
    k++;
    lit.pb(pii(n + 1, m));
    lit_rows[n + 1].pb(k - 1);
    lit_cols[m].pb(k - 1);


    vector<unordered_set<Edge, std::hash<Edge>, EdgeEqual>> adj_list(k,
                                                                     unordered_set<Edge, std::hash<Edge>, EdgeEqual>());
    LOOP(i, k)
    {
        int r = lit[i].first;
        int c = lit[i].second;

        for (int other_r = max(0, r - 2); other_r <= min(n - 1, r + 2); other_r++)
            for (int id : lit_rows[other_r])
            {
                int other_c = lit[id].second;
                int cost;
                switch (abs(other_r - r) + abs(other_c - c))
                {
                    case 0 :
                        continue;
                    case 1:
                        cost = 0;
                        break;
                    default:
                        cost = 1;
                }

                // unordered_set guarantees no double connections to a node
                adj_list[i].insert(Edge(id, cost));
            }

        for (int other_c = max(0, c - 2); other_c <= min(n - 1, c + 2); other_c++)
            for (int id : lit_cols[other_c])
            {
                int other_r = lit[id].first;
                int cost;
                switch (abs(other_r - r) + abs(other_c - c))
                {
                    case 0 :
                        continue;
                    case 1:
                        cost = 0;
                        break;
                    default:
                        cost = 1;
                }

                // unordered_set guarantees no double connections to a node
                adj_list[i].insert(Edge(id, cost));
            }
    }

    vector<ll> dist = dijkstra(0, adj_list);

    if (dist[k - 1] == INF_LL)
        cout << -1;
    else
        cout << dist[k - 1];
}
