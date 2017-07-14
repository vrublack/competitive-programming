/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Wed Jun 28 19:36:22 2017 +0200
    Competition: Codeforces
    Problem id: 279C
    Problem name: Ladder
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <sstream>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <stack>
#include <map>

#define INF INT_MAX
#define LOOP(x, n) for(ll x = 0; x < n; x++)

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pr;

ll mod = 1000000007;


int main()
{
    cin.sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<ll> a(n, 0);
    LOOP(i, n) cin >> a[i];
    vector<pr> queries(m, pr());
    LOOP(i, m) cin >> queries[i].first >> queries[i].second;

    // every sequence can be represented as segments that are nondecreasing (or nonincreasing).
    // store the ends of those segments.
    set<int> down_streak_end;
    set<int> up_streak_end;
    bool increasing = true;
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1 || a[i + 1] < a[i])
            up_streak_end.insert(i);

        if (i == n - 1 || a[i + 1] > a[i])
            down_streak_end.insert(i);
    }

    for (pr q : queries)
    {
        int l = q.first - 1;
        int r = q.second - 1;

        // l exclusive
        bool answer;

        // go up as far as possible
        int up_end = *up_streak_end.lower_bound(l);
        if (up_end >= r)
        {
            answer = true;
        } else
        {
            // can I go the rest in one down streak?
            int down_end = *down_streak_end.lower_bound(up_end);
            answer = down_end >= r;
        }

        if (answer)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

}
