/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Thu Jun 22 17:36:46 2017 +0200
    Competition: Codeforces
    Problem id: 137C
    Problem name: History
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <sstream>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <map>
#include <unordered_map>

#define INF INT_MAX
#define LOOP(x, n) for(int x = 0; x < n; x++)

using namespace std;

typedef long long int ll;
typedef unsigned int ui;
typedef pair<ll, ll> pr;


int main()
{
    // slightly misunderstood problem (number of included events not relevant, only existence), solution from editorial

    ui n;
    cin >> n;
    vector<pr> a(n, pr());
    LOOP(i, n) cin >> a[i].first >> a[i].second;

    // sort by start date
    sort(a.begin(), a.end());

    ll max_end = -1;
    ui result = 0;

    LOOP(i, n)
    {
        ll end = a[i].second;

        if (end < max_end)
            result++;
        else
            max_end = end;
    }

    cout << result;

    return 0;
}
