/**
    Author: Valentin Rublack
    Status: Incorrect large dataset
    Last modified: Sun Jun 25 14:57:04 2017 +0200
    Competition: Google-Code-Jam
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


int main()
{
    // implementing approach from https://www.quora.com/How-many-squares-have-all-four-vertices-in-an-n-times-n-grid-of-dots

    ui T;
    cin >> T;
    LOOP(t_, T)
    {
        ll R, C;
        cin >> R >> C;

        ll n = min(R - 1, C - 1);
        n %= mod;
        ll poss = (C * R % mod) * ((n * (n + 1) % mod) / 2) + (-C - R) * (n * (n + 1) % mod) * ((2 * n + 1) % mod) / 6 +
                  (n * n % mod) * ((n + 1) * (n + 1) % mod) / 4;
        poss %= mod;
        if (poss < 0)
            poss = mod - poss;

        cout << "Case #" << t_ + 1 << ": " << poss << endl;
    }
}
