/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Mon Jun 26 23:13:54 2017 +0200
    Competition: Codeforces
    Problem id: 414A
    Problem name: Mashmokh and Numbers
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

#define INF INT_MAX
#define LOOP(x, n) for(ll x = 0; x < n; x++)

using namespace std;

typedef long long int ll;
typedef unsigned int ui;

ll mod = 1000000007;


int main()
{
    cin.sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;

    // number of gcds
    ll g = n / 2;

    if (g == 0 && k != 0 || g > k)
    {
        // impossible
        cout << -1;
        return 0;
    }

    ll a1 = k - g + 1;
    ll a2 = a1 * 2;

    cout << a1;
    if (n >= 2)
        cout << " " << a2;

    for (ll i = 2; i < n; i++)
    {
        cout << " " << a2 + i - 1;
    }
}
