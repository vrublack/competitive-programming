/**
    Author: Valentin Rublack
    Status: Pretests passed
    Last modified: Tue Jun 27 18:10:04 2017 +0200
    Competition: Codeforces
    Problem id: 820A
    Problem name: Mister B and Book Reading
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
typedef unsigned int ui;
typedef pair<ll, ll> pr;

ll mod = 1000000007;


int main()
{
    cin.sync_with_stdio(false);

    ll c, v0, v1, a, l;
    cin >> c >> v0 >> v1 >> a >> l;

    ll last_page = v0;
    ll day = 2;
    while (last_page < c)
    {
        ll can_read = min(v1, v0 + a * (day - 1));
        // moved l here...
        last_page += can_read - l;
        day++;
    }

    cout << day - 1;
}
