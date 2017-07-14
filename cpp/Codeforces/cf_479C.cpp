/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Mon Jun 5 14:09:02 2017 +0200
    Competition: Codeforces
    Problem id: 479C
    Problem name: Exams
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <algorithm>

#define INF INT_MAX
#define LOOP(x, n) for(int x = 0; x < n; x++)

using namespace std;

typedef long long int ll;
typedef unsigned int uint;


int main()
{
    uint n;
    cin >> n;

    vector<pair<ll, ll>> exams(n, pair<ll, ll>(0, 0));
    LOOP(i, n)
    {
        cin >> exams[i].first >> exams[i].second;
    }

    sort(exams.begin(), exams.end());

    // check if lower last exam date works
    ll last_date = -1;
    LOOP(i, n)
    {
        if (exams[i].second >= last_date)
            last_date = exams[i].second;
        else
            last_date = exams[i].first;
    }

    cout << last_date << endl;

    return 0;
}
