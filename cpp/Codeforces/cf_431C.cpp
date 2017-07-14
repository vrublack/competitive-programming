/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Thu Jun 8 23:07:24 2017 +0200
    Competition: Codeforces
    Problem id: 431C
    Problem name: k-Tree
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
typedef unsigned int uint;


int main()
{
    uint n, k, d;
    cin >> n >> k >> d;

    // n X (not following constraint with d / following it)
    vector<vector<ll>> poss(n + 1, vector<ll>(2, 0));
    poss[0][0] = 1;
    poss[0][1] = 0;

    LOOP(i, n + 1)
    {
        for (int start_num = 1; start_num <= i && start_num <= k; start_num++)
        {
            poss[i][0] += poss[i - start_num][0];
            if (start_num >= d)
                // if the new path starts with at least d, we have already fulfilled the constraint, so we can
                // ignore it for the rest of the path
                poss[i][1] += poss[i - start_num][0];
            else
                poss[i][1] += poss[i - start_num][1];

            poss[i][0] %= 1000000007;
            poss[i][1] %= 1000000007;
        }
    }

    cout << poss[n][1] << endl;

    return 0;
}
