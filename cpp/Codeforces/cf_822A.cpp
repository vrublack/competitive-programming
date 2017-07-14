/**
    Author: Valentin Rublack
    Status: Pretests passed
    Last modified: Sun Jul 2 18:12:45 2017 +0200
    Competition: Codeforces
    Problem id: 822A
    Problem name: I'm bored with life
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>
#include <climits>
#include <numeric>

#define INF INT_MAX
#define LOOP(x, n) for(int x = 0; x < n; x++)

using namespace std;

typedef long long int ll;


ll fact(ll num)
{
    ll result = 1;
    for (ll factor = num; factor > 1; factor--)
        result *= factor;
    return result;
}

int main()
{
    ll A, B;
    cin >> A >> B;
    cout << fact(min(A, B));
}
