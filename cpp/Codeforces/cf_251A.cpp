/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Wed Jul 5 15:41:31 2017 +0200
    Competition: Codeforces
    Problem id: 251A
    Problem name: Points on Line
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
    ll n, d;
    cin >> n >> d;
    READLV(a, n)

    int p1 = 0;
    int p3 = 2;
    ll points = 0;
    while (p1 < n - 2)
    {
        // see how far away p3 can be from p1
        while (p3 < n - 1 && a[p3 + 1] - a[p1] <= d)
            p3++;
        ll dist = p3 - p1;
        if (a[p3] - a[p1] <= d && dist >= 2)
        {
            // for every choice of p3, there are as many choices for p2 as space between p1 and p3
            points += dist * (dist - 1) / 2;
        }

        p1++;
    }

    cout << points;
}
