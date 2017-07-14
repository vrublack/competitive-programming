/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Tue Jun 6 12:38:18 2017 +0200
    Competition: Codeforces
    Problem id: 813B
    Problem name: The Golden Age
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <algorithm>

#define INF INT_MAX
#define LOOP(x, n) for(int x = 0; x < n; x++)

using namespace std;

typedef long long int ll;
typedef unsigned int uint;


int main()
{
    ll x, y, l, r;
    cin >> x >> y >> l >> r;

    // compute all powers of x and y up to r (these aren't many)
    vector<ll> x_pow;
    vector<ll> y_pow;

    x_pow.push_back(1);
    while (x_pow.back() <= r / x)
    {
        ll p = x_pow.back() * x;
        x_pow.push_back(p);
    }

    y_pow.push_back(1);
    while (y_pow.back() <= r / y)
    {
        ll p = y_pow.back() * y;
        y_pow.push_back(p);
    }

    // compute all possible sums of them (still not too many)
    vector<ll> sums;

    for (ll p : x_pow)
        for (ll q : y_pow)
            if (l <= p + q && p + q <= r)
                sums.push_back(p + q);

    if (sums.empty())
    {
        cout << r - l + 1;
        return 0;
    }

    sort(sums.begin(), sums.end());

    // find maximum distance between two elements
    ll max_dist = 0;

    for (int i = 0; i < sums.size() - 1; i++)
    {
        max_dist = max(max_dist, sums[i + 1] - sums[i] - 1);
    }

    max_dist = max(max_dist, sums[0] - l);
    max_dist = max(max_dist, r - sums.back());

    cout << max_dist;

    return 0;
}
