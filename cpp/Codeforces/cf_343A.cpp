/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Wed Jul 5 14:58:07 2017 +0200
    Competition: Codeforces
    Problem id: 343A
    Problem name: Rational Resistance
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


int main()
{
    // from editorial

    ll a, b;
    cin >> a >> b;

    ll x = a;
    ll y = b;
    ll k = 1;

    // From operation 2 we get x/(x + y), and from operation 3 we get (x + y)/y.
    // This is essentially the same as what the Euclidean algorithm gcd(x, y) does backwards because
    // it chops off multiples of y from x by doing x % y.
    while (x > 1 || y > 1)
    {
        if (x % y != 0)
            k += x / y;
        else
            k += x / y - 1;     // we can only start with 1/1

        ll tmp = x;
        x = y;
        if (tmp % y != 0)
            y = tmp % y;
        else
            y = tmp % y + y;
    }

    cout << k;
}
