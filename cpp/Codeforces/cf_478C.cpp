/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Tue Jun 6 11:11:24 2017 +0200
    Competition: Codeforces
    Problem id: 478C
    Problem name: Table Decorations
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

    // solution from http://codeforces.com/blog/entry/18619

    vector<ll> cols(3, 0);
    cin >> cols[0] >> cols[1] >> cols[2];

    sort(cols.begin(), cols.end());

    if ((cols[0] + cols[1]) * 2 <= cols[2])
    {
        cout << cols[0] + cols[1];
    } else
    {
        cout << (cols[0] + cols[1] + cols[2]) / 3;
    }

    return 0;
}
