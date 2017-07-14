/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Tue Jul 4 20:51:16 2017 +0200
    Competition: Codeforces
    Problem id: 235A
    Problem name: LCM Challenge
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


ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    // idea: solution from nhandi (http://codeforces.com/blog/entry/5592?#comment-108764)

    // favorite problem

    ll n;
    cin >> n;

    if (n == 1)
        cout << 1;
    else if (n == 2)
        cout << 2;
    else if (n == 3)
        cout << 6;
    else
    {
        // A theorem says that lcm(a, b, c) = a*b*c*gcd(a, b, c)/(gcd(a, b)*gcd(a, c)*gcd(b, c)).
        // In other words, we want the product of the pairwise gcds to be minimal. In fact, we can
        // always achieve that the gcds are 1.

        if (n % 2 != 0)
        {
            // No pair of these products can have a common factor, since 2 only divides n - 1, and every other
            // divisor would be too large to divide three adjacent numbers.
            cout << n * (n - 1) * (n - 2);
        } else if (n % 3 != 0)
        {
            // We can't choose the last factor to be n - 2 since n and n - 2 wouldn't be coprime then (2|n),
            // so we just decrease it by one.
            cout << n * (n - 1) * (n - 3);
        } else
        {
            // Now the above solution doesn't work anymore since the first and last factor are both divisible by 3.
            // We could chose the factors as n, n - 1 and n - 5 but that is not as good as the following solution (why?):
            cout << (n - 1) * (n - 2) * (n - 3);
        }
    }
}
