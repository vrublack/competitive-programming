/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Mon Jul 3 18:28:26 2017 +0200
    Competition: Codeforces
    Problem id: 822D
    Problem name: My pretty girl Noora
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
#include <set>

#define INF INT_MAX
#define LOOP(x, n) for(int x = 0; x < n; x++)

using namespace std;

typedef long long int ll;
typedef unsigned int ui;


ll mod = 1000000007;


void find_primes(unsigned int n, ui *min_factor)
{
    LOOP(i, n)min_factor[i + 1] = i + 1;

    for (unsigned int p = 2; p <= n / p; p++)
    {
        if (min_factor[p] == p) // prime
            for (unsigned int i = p * 2; i <= n; i += p)
                min_factor[i] = min(min_factor[i], p);
    }
}

int main()
{
    // concept from editorial

    ll t, l, r;
    cin >> t >> l >> r;

    ui min_factor[r];
    find_primes(r, min_factor);
    ll f_dp[r];

    for (int i = 1; i <= r; i++)
    {
        if (i == 1)
            f_dp[i] = 0;
        else if (i == 2)
            f_dp[i] = 1;
        else
        {
            // find smallest prime d such that d|n
            ll d = min_factor[i];

            ll comps = d * (d - 1) / 2 * (i / d);   // last pair of braces important, overflow otherwise
            comps %= mod;

            ll next_round_n = i / d;
            ll remaining_round_comps = f_dp[next_round_n];
            ll total_comps = comps + remaining_round_comps;
            f_dp[i] = total_comps;
        }
    }

    ll result = 0;
    ll t_pow = 1;

    for (ll x = l; x <= r; x++)
    {
        ll exp = x - l;
        result += (t_pow * f_dp[x]) % mod;
        result %= mod;
        t_pow *= t;
        t_pow %= mod;
    }

    cout << result;
}
