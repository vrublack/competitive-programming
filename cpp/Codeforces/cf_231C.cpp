/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Tue Jul 4 16:09:33 2017 +0200
    Competition: Codeforces
    Problem id: 231C
    Problem name: To Add or Not to Add
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
#define READV(a, n) vector<long long int> a(n, 0); LOOP(i, n) cin >> a[i];

using namespace std;

typedef long long int ll;


int main()
{
    FASTIN

    int n, k;
    cin >> n >> k;
    READV(a, n);

    sort(a.begin(), a.end());

    // a accumulated
    vector<ll> a_acc(n, 0);
    LOOP(i, n)
    {
        a_acc[i] = a[i];
        if (i > 0)
            a_acc[i] += a_acc[i - 1];
    }

    ll incr_begin = 0;

    ll occ_max = 1;
    ll opt_num = a[0];

    for (int i = 1; i < n; i++)
    {
        int incr_end = i - 1;

        ll occurrence_cnt = 1;
        // skip as long as number is the same
        while (i < n - 1 && a[i + 1] == a[i])
        {
            i++;
            occurrence_cnt++;
        }

        // how many numbers can we bumb up to a[i]?
        // bumping up y numbers to number x takes x*y - (total sum of all y)
        while (a[i] * (incr_end - incr_begin + 1) - (a_acc[incr_end] - (incr_begin > 0 ? a_acc[incr_begin - 1] : 0)) >
               k)
        {
            incr_begin++;
        }

        ll total_occurrences = occurrence_cnt + (incr_end - incr_begin + 1);
        if (total_occurrences > occ_max)
        {
            occ_max = total_occurrences;
            opt_num = a[i];
        }

        occurrence_cnt++;
    }

    cout << occ_max << " " << opt_num;
}
