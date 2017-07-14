/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Thu Jul 13 22:40:14 2017 +0200
    Competition: Codeforces
    Problem id: 831C
    Problem name: Jury Marks
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
#include <unordered_set>

#define FASTIN cin.sync_with_stdio(false);
#define INF INT_MAX
#define INF_LL LLONG_MAX
#define LOOP(x, n) for(int x = 0; x < n; x++)
#define READLV(a, n) vector<long long int> a(n, 0); LOOP(i, n) cin >> a[i];
#define READBV(a, n) vector<bool> a(n, 0); LOOP(i, n) {int v; cin >> v; a[i] = (bool) v; }
#define pb push_back

using namespace std;

typedef long long int ll;
typedef unsigned int ui;
typedef pair<long, int> ii;


int main()
{
    FASTIN

    ll k, n;
    cin >> k >> n;
    READLV(a, k)
    READLV(b, n)

    unordered_set<ll> a_acc;
    ll prev = 0;
    LOOP(i, k)
    {
        a_acc.insert(prev + a[i]);
        prev += a[i];
    }

    // let b[0] determine the initial element
    ll delta_start = 0;
    unordered_set<ll> valid_initial_els;
    for (int b0_pos = 0; b0_pos < k; b0_pos++)
    {
        delta_start += a[b0_pos];
        ll initial_el = b[0] - delta_start;

        // check for consistency
        bool consistent = true;
        for (int j = 1; j < n; j++)
        {
            if (a_acc.find(b[j] - initial_el) == a_acc.end())
            {
                consistent = false;
                break;
            }
        }

        if (consistent)
            valid_initial_els.insert(initial_el);
    }

    cout << valid_initial_els.size();
}

