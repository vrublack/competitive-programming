/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Wed Jun 28 00:21:13 2017 +0200
    Competition: Codeforces
    Problem id: 746A
    Problem name: Compote
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

#define INF INT_MAX
#define LOOP(x, n) for(ll x = 0; x < n; x++)

using namespace std;

typedef long long int ll;
typedef unsigned int ui;
typedef pair<ll, ll> pr;

ll mod = 1000000007;


int main()
{
    cin.sync_with_stdio(false);

    ui a, b, c;
    cin >> a >> b >> c;

    ui comp_a = a / 1;
    ui comp_b = b / 2;
    ui comp_c = c / 4;

    // the total "units of compot"
    ui comp_units = min(comp_a, min(comp_b, comp_c));

    ui result = comp_units * 1 + comp_units * 2 + comp_units * 4;

    cout << result;
}
