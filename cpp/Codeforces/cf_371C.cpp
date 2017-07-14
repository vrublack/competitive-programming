/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Tue Jun 20 17:53:14 2017 +0200
    Competition: Codeforces
    Problem id: 371C
    Problem name: Hamburgers
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
typedef pair<ll, ll> pr;


ll cost(ll n, int b, int s, int c, int n_b, int n_s, int n_c, int p_b, int p_s, int p_c)
{
    ll cost_b = max<ll>(p_b * (b * n - n_b), 0);
    ll cost_s = max<ll>(p_s * (s * n - n_s), 0);
    ll cost_c = max<ll>(p_c * (c * n - n_c), 0);

    return cost_b + cost_s + cost_c;
}

int main()
{
    string recipe;
    cin >> recipe;
    int b = 0;
    int s = 0;
    int c = 0;
    LOOP(i, recipe.length())
    {
        switch (recipe[i])
        {
            case 'B':
                b++;
                break;
            case 'C':
                c++;
                break;
            case 'S':
                s++;
                break;
        }
    }
    int n_b, n_s, n_c;
    cin >> n_b >> n_s >> n_c;
    int p_b, p_s, p_c;
    cin >> p_b >> p_s >> p_c;
    ll money;
    cin >> money;

    // binary search the largest n such that cost(n) <= money
    // the left boundary is always possible, the right boundary is never possibles
    ll left = 0;
    ll right = (money + p_b * b * n_b + p_c * c * n_c + p_s * s * n_s) / (p_b * b + p_c * c + p_s * s) + 1;

    ll result = -1;

    while (right - left > 1)
    {
        ll pivot = (left + right) / 2;
        ll cost_val = cost(pivot, b, s, c, n_b, n_s, n_c, p_b, p_s, p_c);
        if (cost_val == money)
        {
            // we can't possibly do better
            result = pivot;
            break;
        } else if (cost_val < money)
        {
            // we could potentially make more burgers
            left = pivot;
        } else
        {
            // we can't afford this many burgers
            right = pivot;
        }
    }

    if (result == -1)
        result = left;

    cout << result;
}
