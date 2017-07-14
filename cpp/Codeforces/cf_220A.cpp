/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Sun Jun 18 14:51:27 2017 +0200
    Competition: Codeforces
    Problem id: 220A
    Problem name: Little Elephant and Problem
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


void swap(ui i1, ui i2, vector<ll> &a)
{
    ll tmp = a[i1];
    a[i1] = a[i2];
    a[i2] = tmp;
}

bool try_swap(ui i1, ui i2, vector<ll> &a)
{
    swap(i1, i2, a);
    bool check1 = (i1 == 0 || a[i1 - 1] <= a[i1]) && (i1 == a.size() - 1 || a[i1] <= a[i1 + 1]);
    bool check2 = (i2 == 0 || a[i2 - 1] <= a[i2]) && (i2 == a.size() - 1 || a[i2] <= a[i2 + 1]);
    // swap back
    swap(i1, i2, a);
    return check1 && check2;
}

int main()
{
    ui n;
    cin >> n;
    vector<ll> a(n, 0);
    LOOP(i, n) cin >> a[i];

    // violations of the rule that an element can't be smaller than the previous one
    vector<ui> violations;

    for (ui i = 1; i < n; i++)
        if (a[i] < a[i - 1])
            violations.push_back(i);

    bool possible;

    if (violations.size() == 0)
    {
        possible = true;
    } else if (violations.size() == 1)
    {
        // try swapping elements i and j
        ui i = violations[0];
        while (i < a.size() - 1 && a[i] == a[i + 1])
            i++;
        ui j = violations[0] - 1;
        while (j > 0 && a[j - 1] == a[j])
            j--;
        possible = (i == violations[0] || j == violations[0] - 1) && try_swap(i, j, a);
    } else if (violations.size() == 2)
    {
        // try swapping elements i and j
        possible = try_swap(violations[0] - 1, violations[1], a);
    } else
    {
        possible = false;
    }

    if (possible)
        cout << "YES";
    else
        cout << "NO";
}
