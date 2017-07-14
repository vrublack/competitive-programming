/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Wed Jun 28 17:55:17 2017 +0200
    Competition: ICPC
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
#include <map>

#define INF INT_MAX
#define LOOP(x, n) for(ll x = 0; x < n; x++)

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pr;

ll mod = 1000000007;


int main()
{
    cin.sync_with_stdio(false);

    ll m;
    cin >> m;

    ll c = 299792458;

    cout << m * c * c;
}
