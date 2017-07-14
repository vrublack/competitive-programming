/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Thu Jul 13 00:57:21 2017 +0200
    Competition: Codeforces
    Problem id: 474D
    Problem name: Flowers
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
typedef pair<ll, ll> pll;

const ll mod = 1000000007;

int main()
{
    int T, k;
    cin >> T >> k;

    vector<pll> queries(T, pll());
    ll max_b = -1;
    LOOP(t, T)
    {
        cin >> queries[t].first >> queries[t].second;
        max_b = max(max_b, queries[t].second);
    }

    // "possibilities with i flowers"
    vector<ll> dp(max_b + 1, 0);
    vector<ll> dp_acc(max_b + 1, 0);    // dp accumulated
    dp[0] = 1;
    for (int i = 1; i <= max_b; i++)
    {
        ll white_segment = i - k >= 0 ? dp[i - k] : 0;
        ll no_white_segment = dp[i - 1];
        dp[i] = white_segment + no_white_segment;
        dp[i] %= mod;
        dp_acc[i] = dp_acc[i - 1] + dp[i];
        dp_acc[i] %= mod;
    }

    LOOP(t, T)
    {
        ll result = dp_acc[queries[t].second] - dp_acc[queries[t].first - 1];
        if (result < 0)
            result += mod;
        cout << result << endl;
    }

}
