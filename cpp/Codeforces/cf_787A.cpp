/**
    Author: Valentin Rublack
    Status: Accepted. Wrong before due to unsigned int "underflow". Lessons learned: don't ever use unsigned.
    Last modified: Wed Jun 28 00:56:44 2017 +0200
    Competition: Codeforces
    Problem id: 787A
    Problem name: The Monster
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <sstream>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <stack>

#define INF INT_MAX
#define LOOP(x, n) for(ll x = 0; x < n; x++)

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pr;

ll mod = 1000000007;


int main()
{
    cin.sync_with_stdio(false);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    // brute force
    for (int t = 0; t < 10000000; t++)
    {
        if ((b - d + t*a) % c == 0 && (b - d + t*a) / c >= 0)
        {
            cout << b + t*a;
            return 0;
        }
    }

    cout << -1;
}
