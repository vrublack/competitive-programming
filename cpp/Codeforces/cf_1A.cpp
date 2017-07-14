/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Tue Jul 4 17:56:44 2017 +0200
    Competition: Codeforces
    Problem id: 1A
    Problem name: Theatre Square
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
    ll n, m, a;
    cin >> n >> m >> a;

    ll vertical_needed = m / a;
    if (m % a != 0)
        vertical_needed++;
    ll horizontal_needed = n / a;
    if (n % a != 0)
        horizontal_needed++;

    cout << vertical_needed * horizontal_needed;
}
