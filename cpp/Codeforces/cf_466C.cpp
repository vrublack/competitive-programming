/**
    Author: Valentin Rublack
    Status: Correct
    Last modified: Sat Jun 3 18:36:38 2017 +0200
    Competition: Codeforces
    Problem id: 466C
    Problem name: Number of Ways
*/

#include <iostream>
#include <vector>

#define INF INT_MAX

using namespace std;

typedef long long int ll;
typedef unsigned int uint;


int main()
{
    int n;
    cin >> n;
    vector<ll> a(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // make cumulative array
    for (int i = 0; i < n; i++)
    {
        a[i] += i > 0 ? a[i - 1] : 0;
    }

    // we already know the sum
    if (a[n - 1] % 3 != 0)
    {
        cout << "0" << endl;
        return 0;
    }

    ll sum = a[n - 1] / 3;

    // number of occurrences of 2*sum in the sub-array after and including the index
    vector<int> two_sum_occ(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int prev = (i < n - 1) ? two_sum_occ[i + 1] : 0;
        if (a[i] == 2 * sum && i < n - 1)
            two_sum_occ[i] = prev + 1;
        else
            two_sum_occ[i] = prev;
    }

    ll ways = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] == sum)
        {
            // if we put the first pointer on i, how many choices do we have for the 2nd pointer?
            ways += two_sum_occ[i + 1];
        }
    }

    cout << ways << endl;

    return 0;
}
