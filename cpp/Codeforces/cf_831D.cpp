/**
    Author: Valentin Rublack
    Status: Implementation of min-cost-max-flow not working
    Last modified: Thu Jul 13 19:05:19 2017 +0200
    Competition: Codeforces
    Problem id: 831D
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
#include <sstream>

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
typedef pair<long, int> ii;


// from https://github.com/pjungeblut/ChaosKITs/blob/master/graph/minCostMaxFlow.cpp
static const ll flowlimit = 1LL << 60; // Größer als der maximale Fluss.
struct MinCostFlow
{ // Mit new erstellen!
    static const int maxn = 4000; // Größer als die Anzahl der Knoten.
    static const int maxm = 3000000; // Größer als die Anzahhl der Kanten.
    struct edge
    {
        int node, next;
        ll flow, value;
    } edges[maxm << 1];
    int graph[maxn], queue[maxn], pre[maxn], con[maxn];
    int n, m, source, target, top;
    bool inqueue[maxn];
    ll maxflow, mincost, dis[maxn];

    MinCostFlow()
    {
        memset(graph, -1, sizeof(graph));
        top = 0;
    }

    inline int inverse(int x)
    { return 1 + ((x >> 1) << 2) - x; }

    // Directed edge from u to v, capacity c, weight w.
    inline int addedge(int u, int v, int c, int w)
    {
        edges[top].value = w;
        edges[top].flow = c;
        edges[top].node = v;
        edges[top].next = graph[u];
        graph[u] = top++;
        edges[top].value = -w;
        edges[top].flow = 0;
        edges[top].node = u;
        edges[top].next = graph[v];
        graph[v] = top++;
        return top - 2;
    }

    bool SPFA()
    {
        int point, node, now, head = 0, tail = 1;
        memset(pre, -1, sizeof(pre));
        memset(inqueue, 0, sizeof(inqueue));
        memset(dis, 0x7F, sizeof(dis));
        dis[source] = 0;
        queue[0] = source;
        pre[source] = source;
        inqueue[source] = true;

        while (head != tail)
        {
            now = queue[head++];
            point = graph[now];
            inqueue[now] = false;
            head %= maxn;

            while (point != -1)
            {
                node = edges[point].node;
                if (edges[point].flow > 0 &&
                    dis[node] > dis[now] + edges[point].value)
                {
                    dis[node] = dis[now] + edges[point].value;
                    pre[node] = now;
                    con[node] = point;
                    if (!inqueue[node])
                    {
                        inqueue[node] = true;
                        queue[tail++] = node;
                        tail %= maxn;
                    }
                }
                point = edges[point].next;
            }
        }
        return pre[target] != -1;
    }

    void extend()
    {
        ll w = flowlimit;
        for (int u = target; pre[u] != u; u = pre[u])
            w = min(w, edges[con[u]].flow);
        maxflow += w;
        mincost += dis[target] * w;
        for (int u = target; pre[u] != u; u = pre[u])
        {
            edges[con[u]].flow -= w;
            edges[inverse(con[u])].flow += w;
        }
    }

    void mincostflow()
    {
        maxflow = mincost = 0;
        while (SPFA()) extend();
    }
};


int main()
{
    FASTIN

    ll n, k, p;
    cin >> n >> k >> p;
    READLV(a, n)
    READLV(b, k)

    MinCostFlow *mc = new MinCostFlow();

    // edges from all people to all keys
    LOOP(i, n)
    {
        LOOP(j, k)
        {
            ll u, v;
            u = i + 1;
            v = n + j + 1;

            mc->addedge(u, v, 1, abs(b[j] - a[i]));
        }
    }

    // edges from all keys to the door
    LOOP(j, k)
    {
        ll u = n + j + 1;
        ll v = 0;   // door

        mc->addedge(u, v, 1, abs(b[j] - p));
    }

    mc->mincostflow();

    cout << mc->mincost;
}
