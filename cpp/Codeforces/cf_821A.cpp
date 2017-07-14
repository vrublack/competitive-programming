/**
    Author: Valentin Rublack
    Status: Correct sample output
    Last modified: Sun Jun 25 16:55:11 2017 +0200
    Competition: Codeforces
    Problem id: 821A
    Problem name: Okabe and Future Gadget Laboratory
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
#define LOOP(x, n) for(ll x = 0; x < n; x++)

using namespace std;

typedef long long int ll;
typedef unsigned int ui;

ll mod = 1000000007;


int main()
{
    ui n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n, 0));
    LOOP(i, n) LOOP(j, n) cin >> a[i][j];

    vector<unordered_set<ll>> row_set(n, unordered_set<ll>());
    LOOP(i, n) LOOP(j, n) row_set[i].insert(a[i][j]);

    LOOP(i, n)
    {
        LOOP(j, n)
        {
            ll num = a[i][j];
            if (num == 1)
                continue;
            bool possible = false;
            for (int row = 0; row < n; row++)
                if (row_set[i].find(num - a[row][j]) != row_set[i].end())
                {
                    possible = true;
                    break;
                }

            if (!possible)
            {
                cout << "No";
                return 0;
            }
        }
    }

    cout << "Yes";
}
