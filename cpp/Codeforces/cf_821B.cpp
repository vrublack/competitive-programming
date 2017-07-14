/**
    Author: Valentin Rublack
    Status: Own solution wrong. Implemented editorial solution, correct. Lessons learned:

1) Sometimes O(10,000,000) is fast enough if the operations are simple

2) Always use ll because an expression can overflow in a very subtle way
    Last modified: Mon Jun 26 23:09:44 2017 +0200
    Competition: Codeforces
    Problem id: 821B
    Problem name: Okabe and Banana Trees
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <sstream>
#include <algorithm>
#include <queue>
#include <unordered_set>

#define INF INT_MAX
#define LOOP(x, n) for(ll x = 0; x < n; x++)

using namespace std;

typedef long long int ll;
typedef unsigned int ui;

ll mod = 1000000007;


int l(ll x, ll m, ll b)
{
    return (int) floor(-x / (double) m + b);
}

int main()
{
    // solution from editorial

    ui m, b;
    cin >> m >> b;

    // try out every x
    ll max_x = m * b;
    ll max_bananas = -1;
    for (ll x = 0; x <= max_x; x++)
    {
        ll y = l(x, m, b);
        ll bx = y * (y + 1) / 2;
        ll bananas = (x + 1) * bx + (y + 1) * (x * (x + 1) / 2);
        max_bananas = max(max_bananas, bananas);
    }

    cout << max_bananas;
}
