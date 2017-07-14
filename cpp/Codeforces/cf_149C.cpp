/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Thu Jun 29 01:17:07 2017 +0200
    Competition: Codeforces
    Problem id: 149C
    Problem name: Division into Teams
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

#define INF INT_MAX
#define LOOP(x, n) for(ll x = 0; x < n; x++)
#define IT(x, l) for (auto x = l.begin(); x != l.end(); x++)

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pr;

ll mod = 1000000007;


int main()
{
    cin.sync_with_stdio(false);

    int n;
    cin >> n;

    vector<pr> a(n, pr());
    ll max_player = -1;
    LOOP(i, n)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
        max_player = max(max_player, a[i].first);
    }

    sort(a.begin(), a.end());

    // team A and B
    vector<pr> A;
    vector<pr> B;
    int B_exchange_i = 0;
    ll sum_A = 0;
    ll sum_B = 0;
    LOOP(i, n)
    {
        if (i % 2 == 0)
        {
            A.push_back(a[i]);
            sum_A += a[i].first;

            // can only occur for A since they draw first
            if (sum_A - sum_B > max_player)
            {
                // exchange strongest from A against weakest from B
                ll net_diff = a[i].first - B[B_exchange_i].first;
                B[B_exchange_i] = a[i];
                A.back() = B[B_exchange_i];
                B_exchange_i++;
                sum_A -= net_diff;
                sum_B += net_diff;
            }

        } else
        {
            B.push_back(a[i]);
            sum_B += a[i].first;
        }
    }

    cout << A.size() << endl;
    for (pr p : A)
        cout << p.second << " ";

    cout << endl << B.size() << endl;
    for (pr p : B)
        cout << p.second << " ";


}
