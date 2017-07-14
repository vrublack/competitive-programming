/**
    Author: Valentin Rublack
    Status: Accepted
    Last modified: Fri Jun 30 16:08:25 2017 +0200
    Competition: Codeforces
    Problem id: 225C
    Problem name: Barcode
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>
#include <climits>

#define INF INT_MAX
#define LOOP(x, n) for(int x = 0; x < n; x++)

using namespace std;

typedef long long int ll;


int main()
{
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<vector<char>> board(n, vector<char>(m, ' '));
    LOOP(i, n) LOOP(j, m) cin >> board[i][j];

    // cost to change one column to white
    vector<ll> cost_white(m, 0);
    // we just need this for the sake of cleanliness
    vector<ll> cost_black(m, 0);
    LOOP(j, m)
    {
        // sum blacks in column
        LOOP(i, n)
        {
            if (board[i][j] == '#')
                cost_white[j]++;
        }
        cost_black[j] = n - cost_white[j];
    }

    // cost of board up to i where the last column is colored in black/white
    vector<ll> dp_white(m, 0);
    vector<ll> dp_black(m, 0);

    for (ll j = 0; j < m; j++)
    {
        dp_white[j] = INF;
        ll white_so_far = cost_white[j];
        for (ll b = 1; b <= y; b++)
        {
            if (j - b == -1)
            {
                // end here?
                if (b > x - 1)
                    dp_white[j] = min(dp_white[j], white_so_far);
            } else if (j - b < -1)
            {
                break;
            } else if (b <= x - 1)
            {
                // must be colored white
                white_so_far += cost_white[j - b];
            } else if (b <= y - 1)
            {
                // can be either white or black
                dp_white[j] = min(dp_white[j], white_so_far + dp_black[j - b]);    // turn black and end block here
                white_so_far += cost_white[j - b];
            } else
            {
                // must be black
                dp_white[j] = min(dp_white[j], white_so_far + dp_black[j - b]);
            }
        }

        dp_black[j] = INF;
        ll black_so_far = cost_black[j];
        for (ll b = 1; b <= y; b++)
        {
            if (j - b == -1)
            {
                // end here?
                if (b > x - 1)
                    dp_black[j] = min(dp_black[j], black_so_far);
            } else if (j - b < -1)
            {
                break;
            } else if (b <= x - 1)
            {
                // must be colored black
                black_so_far += cost_black[j - b];
            } else if (b <= y - 1)
            {
                // can be either black or white
                dp_black[j] = min(dp_black[j], black_so_far + dp_white[j - b]);    // turn white and end block here
                black_so_far += cost_black[j - b];
            } else
            {
                // must be white
                dp_black[j] = min(dp_black[j], black_so_far + dp_white[j - b]);
            }
        }
    }

    cout << min(dp_white[m - 1], dp_black[m - 1]);
}
