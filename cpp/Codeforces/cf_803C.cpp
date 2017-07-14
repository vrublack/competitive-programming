/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Sat Jun 10 22:06:18 2017 +0200
    Competition: Codeforces
    Problem id: 803C
    Problem name: Maximal GCD
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
    ll n, k;
    cin >> n >> k;

    ll max_working_divisor = -1;

    if ((k + 1) / 2 > n / k)
    {
        cout << -1;
        return 0;
    }
    ll first_sum = k * (k + 1) / 2;

    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ll d1 = i;
            ll m = n / d1;
            // gauss formula
            if (first_sum <= m)
            {
                max_working_divisor = max(max_working_divisor, d1);
            }

            ll d2 = n / d1;     // counterpart of d1
            m = n / d2;
            if (first_sum <= m)
            {
                max_working_divisor = max(max_working_divisor, d2);
                break;
            }
        }
    }

    if (max_working_divisor != -1)
    {
        LOOP(i, k - 1)
        {
            cout << (i + 1) * max_working_divisor << " ";
        }

        ll sum_so_far = max_working_divisor * (k - 1) * (k) / 2;
        cout << n - sum_so_far;
    } else
    {
        cout << -1;
    }

    return 0;
}
