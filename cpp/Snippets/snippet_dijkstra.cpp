/**
    Author: Valentin Rublack
    Status: Own implementation of Dijkstra's algorithm
    Last modified: Thu Jun 29 12:07:18 2017 +0200
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

#define INF INT_MAX
#define LOOP(x, n) for(ll x = 0; x < n; x++)
#define IT(x, l) for (auto x = l.begin(); x != l.end(); x++)

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pr;
typedef pair<long, int> ii;

ll mod = 1000000007;


struct Edge
{
    int dest;
    ll weight;


    Edge(int dest, ll weight) : dest(dest), weight(weight)
    {}

    Edge()
    {

    }
};


vector<ll> dijkstra(int root, vector<vector<Edge>> &adjList)
{
    unsigned int V = adjList.size();

    vector<ii> Q;
    Q.push_back(ii(0, root));

    // distance from root
    vector<ll> dist(V, ULLONG_MAX);
    dist[root] = 0;

    make_heap(Q.begin(), Q.end(), greater<ii>());

    while (!Q.empty())
    {
        ii pair = Q[0];
        int u = pair.second;
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
            ll alt = dist[u] + adj.weight;
            if (alt < dist[adj.dest])
            {
                dist[adj.dest] = alt;
                // decrease-key is not supported by the heap algorithms, so just throw it in there even though it's already in the queue
                Q.push_back(ii(alt, adj.dest));
                push_heap(Q.begin(), Q.end(), greater<ii>());
            }
        }
    }

    return dist;
}


int main()
{

}
