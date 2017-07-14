/**
    Author: Valentin Rublack
    Status: Implemented from editorial
    Last modified: Fri Jun 30 21:57:49 2017 +0200
    Competition: Codeforces
    Problem id: 348A
    Problem name: Mafia
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>
#include <climits>
#include <numeric>

#define INF INT_MAX
#define LOOP(x, n) for(int x = 0; x < n; x++)

using namespace std;

typedef long long int ll;


int main()
{
    // concept from editorial

    ll n;
    cin >> n;
    vector<ll> a(n, 0);
    LOOP(i, n) cin >> a[i];

    ll max_a = *max_element(a.begin(), a.end());
    ll sum = accumulate(a.begin(), a.end(), 0LL);    // notice the 0LL, overflow otherwise
    ll solution = sum / (n - 1);
    // this is equivalent to "ceil" but doesn't require floating point division
    if (sum % (n - 1) != 0)
        solution++;
    solution = max(solution, max_a);

    cout << solution;
}
