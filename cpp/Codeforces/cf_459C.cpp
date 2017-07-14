/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Sun Jun 18 13:14:49 2017 +0200
    Competition: Codeforces
    Problem id: 459C
    Problem name: Pashmak and Buses
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
#define LOOP(x, n) for(int x = 0; x < n; x++)

using namespace std;

typedef long long int ll;
typedef unsigned int ui;


int main()
{
    // implemented from tutorial

    ui n, d;
    ll k;
    cin >> n >> k >> d;

    // For each student there are k^d sequences of bus numbers. Pigeonhole argument:
    // if k^d < n, then at least two sequences must be the same
    double p = pow(n, 1.0 / d);
    if (k < p)    // k^d can overflow
    {
        cout << -1;
        return 0;
    }

    for (int day = 0; day < d; day++)
    {
        for (int student = 0; student < n; student++)
        {
            ll bus = (student / (ll) (pow(k, day))) % k;
            cout << bus + 1 << " ";
        }
        cout << endl;
    }
}
