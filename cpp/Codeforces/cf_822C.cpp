/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Tue Jul 4 01:08:12 2017 +0200
    Competition: Codeforces
    Problem id: 822C
    Problem name: Hacker, pack your bags!
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

#define FASTIN cin.sync_with_stdio(false);
#define INF INT_MAX
#define LOOP(x, n) for(int x = 0; x < n; x++)

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
typedef pair<pll, pll> ppll;

int main()
{
    // implementation of editorial


    FASTIN

    ll n, x;
    cin >> n >> x;
    // contains each voucher twice: with ((l, 0), (r, cost)) and with ((r, 1), (l, cost)) to ensure they're sorted
    // by first comp (r or l) and that left borders always come before right ones if equal. We could also ensure this
    // with a custom comparator that we pass to sort but that would be too slow.
    vector<ppll> vouchers(2 * n, ppll());
    LOOP(i, n)
    {
        ll l, r, c;
        cin >> l >> r >> c;

        vouchers[i * 2].first = pll(l, 0);
        vouchers[i * 2].second = pll(r, c);
        vouchers[i * 2 + 1].first = pll(r, 1);
        vouchers[i * 2 + 1].second = pll(l, c);
    }

    sort(vouchers.begin(), vouchers.end());

    // min cost of vouchers with duration i
    array<ll, 200002> min_cost{};

    ll best_solution = LLONG_MAX;

    LOOP(i, 2 * n)
    {
        ll b1 = vouchers[i].first.first;
        ll b2 = vouchers[i].second.first;
        ll duration = abs(b1 - b2) + 1;
        ll cost = vouchers[i].second.second;

        if (vouchers[i].first.second == 0)   // left border
        {
            // is there a matching pair?
            if (x - duration >= 0 && min_cost[x - duration] != 0)
            {
                best_solution = min(best_solution, cost + min_cost[x - duration]);
            }
        } else      // right border
        {
            if (min_cost[duration] == 0 || min_cost[duration] > cost)
                min_cost[duration] = cost;
        }
    }

    cout << (best_solution != LLONG_MAX ? best_solution : -1);
}
