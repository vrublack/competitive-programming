/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Sun Jul 9 22:11:21 2017 +0200
    Competition: Codeforces
    Problem id: 424C
    Problem name: Magic Formulas
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


void brute_force(int n, vector<ll> &p)
{
    ll result = 0;
    LOOP(i, n) result ^= p[i];
    LOOP(i, n)
    {
        LOOP(j, n)
        {
            result ^= ((i + 1) % (j + 1));
        }
    }
    cout << "brute force: n = " << n << ": " << result << endl;
}


int main()
{
    FASTIN

    ll n;
    cin >> n;
    READLV(p, n)

    ll result = 0;
    LOOP(i, n) result ^= p[i];

    ll row = 0;
    for (ll m = 2; m <= n; m++)     // the modulus
    {
        ll q = (n + 1) / m;     // how much the number m-1 was added to the last row

        // remove the last q numbers of the previous row
        for (ll i = 0; i < q; i++)
        {
            if ((q - i) % (2 * (m - 1)) == 0)
            {
                // remaining numbers cancel each other out
                break;
            }

            row ^= (n - i) % (m - 1);
        }

        // add m-1 q times
        if (q % 2 == 1)
            row ^= m - 1;

        result ^= row;
    }

    cout << result << endl;
}
