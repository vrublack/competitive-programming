/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Tue Jul 11 23:47:03 2017 +0200
    Competition: Codeforces
    Problem id: 828D
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <climits>
#include <array>

#define FASTIN cin.sync_with_stdio(false);
#define INF INT_MAX
#define LOOP(x, n) for(int x = 0; x < n; x++)
#define READLV(a, n) vector<long long int> a(n, 0); LOOP(i, n) cin >> a[i];
#define READBV(a, n) vector<bool> a(n, 0); LOOP(i, n) {int v; cin >> v; a[i] = (bool) v; }
#define pb push_back

using namespace std;

typedef long long int ll;


int main()
{
    int n, k;
    cin >> n >> k;

    // produce star-shaped graph with exit nodes on the end of each ray
    int available_ray_nodes = n - 1;  // nodes minus centre-node

    int min_way = 2 * (available_ray_nodes / k);
    if (available_ray_nodes % k == 1)
        min_way += 1;
    else if (available_ray_nodes % k >= 2)
        min_way += 2;

    cout << min_way << endl;

    int max_assigned_node = 1;
    for (int ray = 0; ray < k; ray++)
    {
        int ray_nodes = available_ray_nodes / k;
        if (ray < available_ray_nodes % k)
            ray_nodes++;
        int prev_node = 1;  // 1 is centre-node
        LOOP(i, ray_nodes)
        {
            int next_node = ++max_assigned_node;
            cout << prev_node << " " << next_node << endl;
            prev_node = next_node;
        }
    }
}
