/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Fri Jun 30 16:46:38 2017 +0200
    Competition: Codeforces
    Problem id: 18C
    Problem name: Stripe
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>
#include <climits>
#include <numeric>

#define INF INT_MAX
#define LOOP(x, n) for(int x = 0; x < n; x++)

using namespace std;

typedef long long int ll;


int main()
{
    int n;
    cin >> n;
    vector<int> a(n, 0);
    LOOP(i, n) cin >> a[i];

    ll sum = accumulate(a.begin(), a.end(), 0);
    ll sum_so_far = a[0];
    int poss = 0;
    for (int i = 1; i < n; i++)
    {
        if (sum_so_far == sum - sum_so_far)
            poss++;
        sum_so_far += a[i];
    }

    cout << poss;
}
