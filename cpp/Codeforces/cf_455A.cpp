/**
    Author: Valentin Rublack
    Status: Accepted (dp)
    Last modified: Mon Jun 5 16:11:29 2017 +0200
    Competition: Codeforces
    Problem id: 455A
    Problem name: Boredom
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
    uint n;
    cin >> n;
    uint max_val = 100000;
    vector<ll> hist(max_val + 1, 0);
    LOOP(i, n)
    {
        int val;
        cin >> val;
        hist[val]++;
    }

    // make histogram of reward
    LOOP(i, hist.size())
    {
        hist[i] *= i;
    }

    // dp
    ll opt_prev = 0;
    ll opt_prev_prev = -1;

    LOOP(i, hist.size())
    {
        ll take = opt_prev_prev + hist[i];
        ll dont_take = opt_prev;

        opt_prev_prev = opt_prev;
        opt_prev = max(take, dont_take);
    }

    cout << opt_prev << endl;

    return 0;
}
